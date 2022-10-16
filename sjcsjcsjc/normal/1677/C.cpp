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

int n,cnt,a[100010],b[100010],nxt[100010],vis[100010];

inline void dfs(int x)
{
	cnt++;vis[x]=1;
	if(!vis[nxt[x]]) dfs(nxt[x]);
}

signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++) cin>>b[i];
		for(int i=1;i<=n;i++) nxt[a[i]]=b[i],vis[i]=0;
		int num=0;
		for(int i=1;i<=n;i++) if(!vis[i]){
			cnt=0;dfs(i);num+=cnt/2;
		}
		long long ans=0ll;
		for(int i=1;i<=num;i++) ans+=1ll*(n-2*i+1);
		cout<<ans*2ll<<'\n';
	}
	return 0;
}