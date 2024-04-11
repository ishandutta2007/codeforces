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

int n,a[210],dp[210][410];

signed main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+n+1);
		for(int i=1;i<=2*n;i++) dp[1][i]=abs(i-a[1]);
		for(int i=2;i<=n;i++){
			for(int j=1;j<=2*n;j++){
				dp[i][j]=INF;
				for(int k=1;k<j;k++){
					dp[i][j]=min(dp[i][j],dp[i-1][k]+abs(j-a[i]));
				}
			}
		}
		int ans=INF;
		for(int i=1;i<=2*n;i++) ans=min(ans,dp[n][i]);
		cout<<ans<<'\n';
	}
	return 0;
}