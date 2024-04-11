#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
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

int b[400010],minv[1600010],tag[1600010];
bool vis[400010];

inline void init(int o,int l,int r)
{
	minv[o]=tag[o]=0;
	if(r>l){
		int mid=(l+r)/2;
		init(o*2,l,mid);
		init(o*2+1,mid+1,r);
	}
}

inline void pushdown(int o)
{
	tag[o*2]+=tag[o];tag[o*2+1]+=tag[o];
	minv[o*2]+=tag[o];minv[o*2+1]+=tag[o];
	tag[o]=0;
}

inline void pushup(int o)
{
	minv[o]=min(minv[o*2],minv[o*2+1]);
}

inline void update(int o,int l,int r,int x,int y,int val)
{
	if(r<x||l>y) return;
	if(x<=l&&r<=y){
		tag[o]+=val;
		minv[o]+=val;
		return;
	}
	pushdown(o);
	int mid=(l+r)/2;
	update(o*2,l,mid,x,y,val);
	update(o*2+1,mid+1,r,x,y,val);
	pushup(o);
}

signed main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n;cin>>n;
		for(int i=1;i<=2*n;i++) vis[i]=0;
		for(int i=1;i<=n;i++) cin>>b[i],vis[b[i]]=1;
		vector<int> vec;
		for(int i=1;i<=2*n;i++) if(!vis[i]) vec.push_back(i);
		init(1,1,n+1);
		for(int i=0;i<=n;i++) update(1,1,n+1,i+1,i+1,i);
		int pos1=1;
		for(int i=n;i>=1;i--){
			int pos=lower_bound(vec.begin(),vec.end(),b[i])-vec.begin();
			update(1,1,n+1,pos+1,n+1,-1);
			if(minv[1]<0){
				pos1=i+1;break;
			}
		}
		init(1,1,n+1);
		for(int i=0;i<=n;i++) update(1,1,n+1,i+1,i+1,i);
		int pos2=n;
		for(int i=1;i<=n;i++){
			int pos=vec.size()-(lower_bound(vec.begin(),vec.end(),b[i])-vec.begin());
			update(1,1,n+1,pos+1,n+1,-1);
			if(minv[1]<0){
				pos2=i-1;break;
			}
		}
		int cnt=0;
		for(int i=0;i<=n;i++){
			if(i<=pos2&&i+1>=pos1) cnt++;
		}
		cout<<cnt<<'\n';
	}
	return 0;
}