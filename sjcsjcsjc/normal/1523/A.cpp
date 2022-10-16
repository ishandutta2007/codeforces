#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n,m;cin>>n>>m;
		vector<int> v;
		int now=0;
		for(int i=1;i<=n;i++){
			char x;cin>>x;
			if(x=='0') now++;
			else{
				v.push_back(now);
				now=0;
			}
		}
		v.push_back(now);
		if(v.size()==1){
			for(int i=1;i<=n;i++) cout<<'0';
			cout<<'\n';
			continue;
		}
		for(int i=0;i<v.size();i++){
			if(i==0){
				int rem=max(v[i]-m,0);
				for(int j=1;j<=rem;j++) cout<<'0';
				for(int j=1;j<=v[i]-rem;j++) cout<<'1';
			}
			else if(i==v.size()-1){
				int rem=max(v[i]-m,0);
				for(int j=1;j<=v[i]-rem;j++) cout<<'1';
				for(int j=1;j<=rem;j++) cout<<'0';
			}
			else{
				int num=min(m,v[i]/2);
				for(int j=1;j<=num;j++) cout<<'1';
				for(int j=1;j<=v[i]-2*num;j++) cout<<'0';
				for(int j=1;j<=num;j++) cout<<'1'; 
			}
			if(i<v.size()-1) cout<<'1';
		}
		cout<<'\n';
	}
	return 0;
}