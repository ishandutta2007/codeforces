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

int n,m,bit[1000010];
char c[1000010];
bool vis[1000010];

inline void add(int p,int v)
{
	while(p<=m){
		bit[p]+=v;
		p+=p&(-p);
	}
}

inline int sum(int p)
{
	int s=0;
	while(p!=0){
		s+=bit[p];
		p-=p&(-p);
	}
	return s;
}

signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n*m;i++) cin>>c[i];
		for(int i=1;i<=m;i++) bit[i]=0;
		for(int i=0;i<m;i++) vis[i]=0;
		int cnt=0,pre=0,col=0,off=0;
		for(int i=1;i<=n*m;i++){
			if(c[i]=='1'){
				if(!vis[(i-1)%m]) col++,vis[(i-1)%m]=1;
				if(pre){
					if(i-pre<m){
						int now=(i-1)%m,nxt=(now+m-(i-pre)-1)%m;
						if(now<=nxt){
							add(now+1,1);
							if(nxt<m-1) add(nxt+2,-1);
						}
						else{
							off++;
							add(nxt+2,-1);add(now+1,1);
						}
					}
				}
				pre=i;cnt++;
			} 
			cout<<cnt+col-off-sum((i-1)%m+1)<<' ';
		}
		cout<<'\n';
	}
	return 0;
}