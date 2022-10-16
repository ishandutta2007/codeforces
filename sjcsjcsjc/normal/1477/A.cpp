#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define int long long
using namespace __gnu_pbds;
using namespace std;

int a[200010];

inline int gcd(int a,int b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}

signed main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n,k;cin>>n>>k;
		for(int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+n+1);
		int g=0;
		for(int i=1;i<n;i++) g=gcd(g,a[i+1]-a[i]);
		int val=a[1]%g;
		if(val<0) val+=g;
		int now=k%g;
		if(now<0) now+=g;
		if(val==now) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}