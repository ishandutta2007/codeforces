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

int a[110],b[110],dp[110][10010];

signed main()
{
	ios::sync_with_stdio(false);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++) cin>>b[i];
		int ans=0;
		for(int i=1;i<=n;i++) ans+=a[i]*a[i]*(n-1);
		for(int i=1;i<=n;i++) ans+=b[i]*b[i]*(n-1);
		for(int i=0;i<=n;i++) for(int j=0;j<=10000;j++) dp[i][j]=INF;
		dp[0][0]=0;
		int sum=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=10000;j++){
				dp[i][j+a[i]]=min(dp[i][j+a[i]],dp[i-1][j]+a[i]*j+b[i]*(sum-j));
				dp[i][j+b[i]]=min(dp[i][j+b[i]],dp[i-1][j]+b[i]*j+a[i]*(sum-j));
			}
			sum+=a[i]+b[i];
		}
		int res=INF;
		for(int i=0;i<=10000;i++) res=min(res,dp[n][i]);
		ans+=2*res;
		cout<<ans<<'\n';
	}
	return 0;
}