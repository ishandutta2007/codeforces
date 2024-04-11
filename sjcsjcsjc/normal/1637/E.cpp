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

int a[300010],cnt,val[300010],tot[300010];
map<int,int> mp,pm;
vector<int> v[300010];
cc_hash_table<long long,bool,custom_hash> p;

signed main()
{
	ios::sync_with_stdio(false);
	int t;cin>>t;
	while(t--){
		int n,m;cin>>n>>m;
		mp.clear();pm.clear();
		for(int i=1;i<=n;i++) cin>>a[i],mp[a[i]]=1;
		cnt=0;
		for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++){
			cnt++;
			pm[it->first]=cnt;
			val[cnt]=(it->first);
		}
		p.clear();
		for(int i=1;i<=m;i++){
			int x,y;cin>>x>>y;
			x=pm[x];y=pm[y];
			p[1ll*x*cnt+y]=1;
			p[1ll*y*cnt+x]=1;
		}
		for(int i=1;i<=cnt;i++) tot[i]=0;
		for(int i=1;i<=n;i++) a[i]=pm[a[i]],tot[a[i]]++;
		for(int i=1;i<=n;i++) v[i].clear();
		for(int i=1;i<=cnt;i++) v[tot[i]].push_back(i);
		vector<int> res;
		for(int i=1;i<=n;i++) if(!v[i].empty()) res.push_back(i);
		long long ans=0ll;
		for(int i=0;i<res.size();i++){
			int x=res[i];
			for(int j=0;j<v[x].size();j++){
				int y=v[x][j],z=-1;
				for(int k=v[x].size()-1;k>j;k--){
					int u=v[x][k];
					if(!p[1ll*y*cnt+u]){
						z=u;break;
					}
				}
				if(z!=-1) ans=max(ans,1ll*(x+x)*(val[y]+val[z]));
			}
		}
		for(int i=0;i<res.size();i++){
			int x=res[i];
			for(int j=i+1;j<res.size();j++){
				int y=res[j];
				for(int k=0;k<v[x].size();k++){
					int u=v[x][k],z=-1;
					for(int l=v[y].size()-1;l>=0;l--){
						int o=v[y][l];
						if(!p[1ll*u*cnt+o]){
							z=o;break;
						}
					}
					if(z!=-1) ans=max(ans,1ll*(x+y)*(val[u]+val[z]));
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}