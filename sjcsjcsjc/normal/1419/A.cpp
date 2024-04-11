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
		int n;cin>>n;
		string s;cin>>s;
		if(n%2==0){
			bool flag=false;
			for(int i=2;i<=n;i+=2) if((s[i-1]-'0')%2==0){
				flag=true;break;
			}
			if(flag) cout<<2<<'\n';
			else cout<<1<<'\n';
		}
		else{
			bool flag=false;
			for(int i=1;i<=n;i+=2) if((s[i-1]-'0')%2==1){
				flag=true;break;
			}
			if(flag) cout<<1<<'\n';
			else cout<<2<<'\n';
		}
	}	
	return 0;
}