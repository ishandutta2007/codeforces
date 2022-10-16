#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

int n,x[5010],y[5010],ans[5010],vis[5010];

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>x[i]>>y[i];
	ans[1]=1;vis[1]=1;
	for(int i=2;i<=n;i++){
		long long dist=0;
		int pos=0;
		for(int j=1;j<=n;j++) if(!vis[j]){
			long long val=1ll*(x[j]-x[ans[i-1]])*(x[j]-x[ans[i-1]])+1ll*(y[j]-y[ans[i-1]])*(y[j]-y[ans[i-1]]);
			if(val>dist){
				dist=val;
				pos=j;
			}
		}
		ans[i]=pos;
		vis[pos]=1;
	}
	for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
	cout<<endl; 
	return 0;
}