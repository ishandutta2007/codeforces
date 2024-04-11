#include <bits/stdc++.h>

using namespace std;
using nagai = long long;
#define sz(x) int((x).size())

const int N=300300;
int n;
int p[N];
int inv[N];
vector<pair<int,int>>ans;
void swp(int a,int b){
	if(a==b)return;
	ans.emplace_back(a,b);
	int x=p[a],y=p[b];
	swap(p[a],p[b]);
	swap(inv[x],inv[y]);
//	for(int i=0;i<n;++i)
//		cerr<<p[i]<<' ';
//	cerr<<'\n';
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>p[i],--p[i];
		inv[p[i]]=i;
	}
	int val=n/2;
	for(int i=1;i<n/2;++i){
		if(p[i]==i)continue;
		if(abs(inv[i]-i)>=val)
			swp(inv[i],i);
		else{
			if(inv[i]>=n/2)
				swp(inv[i],0);
			swp(inv[i],n-1);
			swp(inv[i],i);
		}
	}
	for(int i=n/2;i<n;++i){
		if(p[i]==i)continue;
		swp(inv[i],0);
		swp(inv[i],i);
	}
	if(inv[0]!=0)
		swp(inv[0],0);
	cout<<ans.size()<<'\n';
	for(auto&[x,y]:ans)
		cout<<x+1<<' '<<y+1<<'\n';
	assert(is_sorted(p,p+n));
	return 0;
}