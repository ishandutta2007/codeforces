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

int a[5010],p[5010];

inline int find_set(int x)
{
	return p[x]==x?x:p[x]=find_set(p[x]);
}

inline void unite(int x,int y)
{
	int rootx=find_set(x),rooty=find_set(y);
	p[rootx]=rooty;
}

signed main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n;cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i],p[i]=i;
		p[n+1]=n+1;
		for(int i=1;i<=n;i++) if(a[i]==1) unite(i,i+1);
		long long ans=0ll;
		for(int i=1;i<=n;i++){
			int ind=max(n-i,1);
			if(a[i]>ind) ans+=(long long)(a[i]-ind),a[i]=ind;
			while(a[i]>1){
				int now=i;ans++;
				while(now<=n){
					a[now]--;
					if(a[now]==1) unite(now,now+1);
					if(now+a[now]+1>n) break;
					else now=find_set(now+a[now]+1);
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}