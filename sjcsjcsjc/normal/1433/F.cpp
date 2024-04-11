#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define INF 1000000007
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

int n,m,k,a[100][100],dp[100][100],f[100][100];

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	for(int o=0;o<k;o++) dp[0][o]=-INF;
	dp[0][0]=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=m;j++) for(int o=0;o<k;o++) f[j][o]=-INF;
		f[0][0]=0;
		for(int j=1;j<=m;j++){
			for(int l=m/2;l>=1;l--){
				for(int o=0;o<k;o++){
					f[l][(o+a[i][j])%k]=max(f[l][(o+a[i][j])%k],f[l-1][o]+a[i][j]);
				}
			}
		}
		for(int o=0;o<k;o++) dp[i][o]=-INF;
		for(int o=0;o<k;o++){
			int ans=-INF;
			for(int l=0;l<=m/2;l++){
				ans=max(ans,f[l][o]);
			}
			for(int j=0;j<k;j++){
				dp[i][(j+o)%k]=max(dp[i][(j+o)%k],dp[i-1][j]+ans);
			}
		}
	}
	cout<<dp[n][0]<<endl;
	return 0;
}