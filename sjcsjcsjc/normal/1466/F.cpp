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

int n,m,p[500010],pw[500010];

inline int find_set(int x)
{
	return p[x]==x?x:p[x]=find_set(p[x]);
}

inline bool unite(int x,int y)
{
	int rootx=find_set(x),rooty=find_set(y);
	if(rootx==rooty) return false;
	p[rooty]=rootx;
	return true;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	pw[0]=1ll;
	for(int i=1;i<=n;i++) pw[i]=1ll*pw[i-1]*2%MOD;
	for(int i=0;i<=m;i++) p[i]=i;
	vector<int> ans;
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		if(k==1){
			int x;cin>>x;
			if(unite(0,x)){
				ans.push_back(i);
			}
		}
		else{
			int x,y;cin>>x>>y;
			if(unite(x,y)){
				ans.push_back(i);	
			}
		}
	}
	cout<<pw[ans.size()]<<" "<<ans.size()<<'\n';
	for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
	cout<<'\n';
	return 0;
}