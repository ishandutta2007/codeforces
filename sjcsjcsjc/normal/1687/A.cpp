#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
//#define int long long
using namespace __gnu_pbds;
using namespace std;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int a[200010];
long long sum[200010];

signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin>>t;
	while(t--){
		int n,k;cin>>n>>k;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++) sum[i]=sum[i-1]+1ll*a[i];
		if(k<n){
			long long ans=0ll;
			for(int i=1;i<=n-k+1;i++){
				ans=max(ans,sum[i+k-1]-sum[i-1]);
			}
			cout<<ans+1ll*k*(k-1)/2<<'\n';
		}
		else{
			long long ans=sum[n];
			cout<<ans+1ll*(2*k-n-1)*n/2<<'\n';
		}
	}
	return 0;
}