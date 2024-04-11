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

int n,ans,l[200010],r[200010],val[200010];
vector<int> v[200010];

inline void dfs(int x,int pr)
{
	long long sum=0ll;
	for(int i=0;i<v[x].size();i++) if(v[x][i]!=pr){
		dfs(v[x][i],x);sum+=1ll*val[v[x][i]];
	}
	if(sum>r[x]){
		val[x]=r[x];
	}
	else if(sum>=l[x]&&sum<=r[x]) val[x]=sum;
	else{
		ans++;val[x]=r[x];
	}
}

signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++) v[i].clear();
		for(int i=2;i<=n;i++){
			int x;cin>>x;v[x].push_back(i);
		}
		for(int i=1;i<=n;i++) cin>>l[i]>>r[i];
		ans=0;dfs(1,-1);
		cout<<ans<<'\n';
	}
	return 0;
}