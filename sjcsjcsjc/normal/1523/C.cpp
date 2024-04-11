#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

int n,a[10010],b[10010];

signed main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		int now=1;
		for(int i=1;i<=n;i++) b[i]=0;
		for(int i=1;i<=n;i++){
			b[now]++;
			for(int j=1;j<now;j++) cout<<b[j]<<'.';
			cout<<b[now]<<'\n';
			if(i<n){
				if(a[i+1]==1){
					now++;b[now]=0;
				}
				else{	
					for(int j=now;j>=1;j--) if(b[j]+1==a[i+1]){
						now=j;break;
					}
				}
			}
		}
	}
	return 0;
}