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

int n,q,cnt,tot,pri[1000010],rev[1000010],a[1000010],num[1000010];
vector<int> v[1000010],g[1000010];
bool vis[1000010];
cc_hash_table<long long,int,custom_hash> ok;

inline void init()
{
	for(int i=2;i<=1000000;i++){
        if(!vis[i]) pri[++cnt]=i,rev[i]=cnt;
        for(int j=1;j<=cnt&&i*pri[j]<=1000000;j++){
            vis[i*pri[j]]=1;
            if(i%pri[j]==0) break;
        }
    }
}

inline void dfs(int x)
{
	num[x]=tot;
	for(int i=0;i<v[x].size();i++) if(!num[v[x][i]]){
		dfs(v[x][i]);
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	init();
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int p=a[i];
		for(int j=2;j*j<=a[i];j++) if(p%j==0){
			v[cnt+i].push_back(rev[j]);
			v[rev[j]].push_back(cnt+i);
			while(p%j==0) p/=j;
		}
		if(p>1){
			v[cnt+i].push_back(rev[p]);
			v[rev[p]].push_back(cnt+i);
		}
	}
	for(int i=1;i<=cnt+n;i++) if(!num[i]){
		tot++;dfs(i);
	}
	for(int i=1;i<=n;i++){
		int p=a[i];
		vector<int> vec;
		for(int j=2;j*j<=a[i];j++) if(p%j==0){
			vec.push_back(num[rev[j]]);
			while(p%j==0) p/=j;
		}
		if(p>1){
			vec.push_back(num[rev[p]]);
		}
		p=a[i]+1;
		for(int j=2;j*j<=a[i]+1;j++) if(p%j==0){
			vec.push_back(num[rev[j]]);
			while(p%j==0) p/=j;
		}
		if(p>1){
			vec.push_back(num[rev[p]]);
		}
		sort(vec.begin(),vec.end());
		vec.erase(unique(vec.begin(),vec.end()),vec.end());
		for(int j=0;j<vec.size();j++){
			for(int k=j+1;k<vec.size();k++){
				ok[1ll*vec[j]*tot+1ll*vec[k]]=ok[1ll*vec[k]*tot+1ll*vec[j]]=1;
			}
		}
	}
	for(int i=1;i<=q;i++){
		int s,t;cin>>s>>t;
		if(num[cnt+s]==num[cnt+t]){
			cout<<"0\n";
			continue;
		}
		if(a[s]%2==0||a[t]%2==0){
			cout<<"1\n";
			continue;
		}
		if(ok[1ll*num[cnt+s]*tot+1ll*num[cnt+t]]){
			cout<<"1\n";
			continue;
		}
		cout<<"2\n";
	}
	return 0;
}