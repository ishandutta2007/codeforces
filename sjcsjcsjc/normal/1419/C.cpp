#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

int n,x,a[1010];

signed main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		cin>>n>>x;
		for(int i=1;i<=n;i++) cin>>a[i];
		bool flag=true;
		for(int i=1;i<=n;i++) if(a[i]!=x){
			flag=false;break;
		}
		if(flag){
			cout<<0<<'\n';continue;
		}
		int sum=0;
		for(int i=1;i<=n;i++) sum+=a[i];
		if(sum==n*x){
			cout<<1<<'\n';continue;
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]==x) cnt++;
		}
		if(cnt>0){
			cout<<1<<'\n';continue;
		}
		cout<<2<<'\n';
	}
	return 0;
}