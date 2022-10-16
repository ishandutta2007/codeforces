#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define INF 1000000000000000007ll
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

int c[510][510];
long long sum1[510],sum2[510];

signed main()
{
	ios::sync_with_stdio(false);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		long long sum=0ll;
		for(int i=1;i<=2*n;i++){
			for(int j=1;j<=2*n;j++){
				cin>>c[i][j];
				if(i>n&&j>n) sum+=1ll*c[i][j];
			}
		}
		long long ans=INF;
		ans=min(ans,1ll*c[1][n+1]);ans=min(ans,1ll*c[1][2*n]);
		ans=min(ans,1ll*c[n][n+1]);ans=min(ans,1ll*c[n][2*n]);
		ans=min(ans,1ll*c[n+1][1]);ans=min(ans,1ll*c[n+1][n]);
		ans=min(ans,1ll*c[2*n][1]);ans=min(ans,1ll*c[2*n][n]);
		cout<<ans+sum<<'\n';
	}
	return 0;
}