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

int a[1000010],b[1000010];
vector<int> v[1000010];
long long dp[1000010][2];

inline int gcd(int a,int b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}

signed main()
{
	ios::sync_with_stdio(false);
	int t;cin>>t;
	while(t--){
		int n,m;cin>>n>>m;
		for(int i=1;i<=n;i++) cin>>a[i];
		int g=0;
		for(int i=1;i<=m;i++) cin>>b[i],g=gcd(g,b[i]);
		for(int i=0;i<g;i++) v[i].clear();
		for(int i=1;i<=n;i++){
			v[i%g].push_back(a[i]);
		}
		long long ans0=0ll,ans1=0ll;
		for(int i=0;i<g;i++) if(!v[i].empty()){
			dp[0][0]=0ll;dp[0][1]=-INF;
			for(int j=0;j<v[i].size();j++){
				dp[j+1][0]=max(dp[j][0]+v[i][j],dp[j][1]-v[i][j]);
				dp[j+1][1]=max(dp[j][0]-v[i][j],dp[j][1]+v[i][j]);
			}
			ans0+=dp[v[i].size()][0];
			ans1+=dp[v[i].size()][1];
		}
		cout<<max(ans0,ans1)<<'\n';
	}
	return 0;
}