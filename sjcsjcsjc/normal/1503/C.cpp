#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define int long long
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

int n,dp[100010];
pair<pair<int,int>,int> a[100010];

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].first.first>>a[i].first.second;
		a[i].second=i;ans+=a[i].first.second;
	}
	sort(a+1,a+n+1);
	int mx=a[1].first.first+a[1].first.second;
	for(int i=2;i<=n;i++){
		ans+=max(0ll,a[i].first.first-mx);
		mx=max(mx,a[i].first.first+a[i].first.second);
	}
	cout<<ans<<'\n';
	return 0;
}