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

int a[200010],b[200010],p[200010];
long long sum[200010];
vector<int> v[200010];
bool used[200010];

inline int find_set(int x)
{
	return p[x]==x?x:p[x]=find_set(p[x]);
}

signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin>>t;
	while(t--){
		int n,m;cin>>n>>m;
		for(int i=0;i<=n;i++) v[i].clear(),used[i]=0,p[i]=i;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++) cin>>b[i];
		for(int i=1;i<=n;i++) a[i]-=b[i];
		for(int i=1;i<=n;i++) sum[i]=sum[i-1]+1ll*a[i];
		for(int i=0;i<=n;i++) if(sum[i]==0ll) used[i]=1;
		for(int i=1;i<=n;i++) if(used[i]) p[find_set(i-1)]=find_set(i);
		queue<pair<int,int> > q;
		for(int i=1;i<=m;i++){
			int l,r;cin>>l>>r;
			v[l-1].push_back(r);v[r].push_back(l-1);
			if(used[l-1]&&used[r]) q.push(make_pair(l-1,r));
		}
		while(!q.empty()){
			pair<int,int> t=q.front();q.pop();
			int l=t.first,r=t.second;
			while(true){
				l=find_set(l)+1;
				if(l>r) break;
				used[l]=1;p[find_set(l-1)]=find_set(l);
				for(int i=0;i<v[l].size();i++){
					int u=v[l][i];
					if(used[u]){
						if(l<u) q.push(make_pair(l,u));
						else q.push(make_pair(u,l));
					}
				}
			}
		}
		bool flag=true;
		for(int i=0;i<=n;i++) if(!used[i]){
			flag=false;break;
		}
		if(flag) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}