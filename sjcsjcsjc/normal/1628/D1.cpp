#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define MOD 1000000007
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

const int rev2=500000004;

int x,y,dp[2010][2010];

signed main()
{
	ios::sync_with_stdio(false);
	int t;cin>>t;
	while(t--){
		int n,m,k;cin>>n>>m>>k;
		x=m;y=n-m;
		for(int i=1;i<=x;i++) dp[i][0]=1ll*k*i%MOD;
		for(int i=1;i<=y;i++) dp[0][i]=0;
		for(int i=1;i<=x;i++){
			for(int j=1;j<=y;j++){
				dp[i][j]=1ll*(dp[i-1][j]+dp[i][j-1])*rev2%MOD;
			}
		}
		cout<<dp[x][y]<<'\n';
	}
	return 0;
}