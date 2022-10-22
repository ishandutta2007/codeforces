#include <bits/stdc++.h>

using namespace std;
using nagai = long long;
#define sz(x) int((x).size())

const int N=100100;
pair<int,int> a[N];

nagai xtime(){
	return clock()*1000/CLOCKS_PER_SEC;
}

int gcd(int a,int b){
	 if(a==0)return b;
	 if(b==0)return a;
	 return __gcd(a,b);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	map<int,int>mp;
	for(int i=0;i<n;++i){
		int x;
		cin>>a[i].first;
		a[i].second=i;
	}
	/*
	n=0;
	vector<int>b;
	for(auto&[x,y]:mp){
		for(int i=0;i<min(2,y);++i){
			a[n++]=x;
		}
		for(int i=0;i<max(0,y-2);++i)
			b.push_back(x);
	}
	*/
	mt19937 rnd(239);
	vector<bool>used(n);
	while(xtime()<450){
		fill(used.begin(),used.end(),false);
		shuffle(a,a+n,rnd);
		int cur=0;
		vector<int>inter;
		for(int i=0;i<n;++i){
			int kek=gcd(cur,a[i].first);
			if(kek!=cur)inter.push_back(i),used[i]=true;
			cur=kek;
			if(cur==1){
				int kek=a[inter[0]].first;
				for(int x:inter)
					kek=__gcd(kek,a[x].first);
				if(kek!=1){
					break;
				}
				int mem=0;
				for(int i=0;i<n;++i)
					if(!used[i])
						mem=gcd(mem,a[i].first);
				if(mem!=1){
					break;
				}
				cout<<"YES\n";
				vector<int>ans(n);
				for(int i=0;i<n;++i)
					if(used[i])ans[a[i].second]=1;
				for(int i=0;i<n;++i)
					cout<<ans[i]+1<<' ';
				cout<<'\n';
				return 0;
			}
		}
	}
	cout<<"NO\n";
	return 0;
}