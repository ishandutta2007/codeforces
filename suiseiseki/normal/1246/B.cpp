#include <map>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define Maxn 100000
#define ll long long
int a[Maxn+5];
int n,k;
map<vector<pair<int,int> >,int> mp;
vector<pair<int,int> > change(const vector<pair<int,int> > &x){
	static vector<pair<int,int> > ans;
	ans.clear();
	int now;
	for(int i=0;i<(int)x.size();i++){
		now=x[i].second;
		now=(k-now%k)%k;
		if(now>0){
			ans.push_back(make_pair(x[i].first,now));
		}
	}
	return ans;
}
void work(int x,vector<pair<int,int> > &p){
	p.clear();
	for(int i=2;i*i<=x;i++){
		if(x%i==0){
			p.push_back(make_pair(i,0));
			while(x%i==0){
				p.back().second++;
				x/=i;
			}
		}
	}
	if(x>1){
		p.push_back(make_pair(x,1));
	}
}
void clear(vector<pair<int,int> > &p){
	static vector<pair<int,int> > ans;
	ans.clear();
	for(int i=0;i<(int)p.size();i++){
		if(p[i].second%k==0){
			continue;
		}
		ans.push_back(make_pair(p[i].first,p[i].second%k));
	}
	p=ans;
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	vector<pair<int,int> > p,q;
	ll ans=0;
	for(int i=1;i<=n;i++){
		work(a[i],p);
		clear(p);
		q=change(p);
		if(mp.count(q)>0){
			ans+=mp[q];
		}
		mp[p]++;
	}
	cout<<ans<<endl;
	return 0;
}