#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define INF 1000000007
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

int n,a[300010],maxv[1200010],tag[1200010];
pair<int,int> b[300010];

inline void build(int o,int l,int r)
{
	tag[o]=0;
	if(l==r) maxv[o]=-l;
	else{
		int mid=(l+r)/2;
		build(o*2,l,mid);
		build(o*2+1,mid+1,r);
		maxv[o]=max(maxv[o*2],maxv[o*2+1]);
	}
}

inline void pushdown(int o)
{
	if(tag[o]){
		maxv[o*2]+=tag[o];tag[o*2]+=tag[o];
		maxv[o*2+1]+=tag[o];tag[o*2+1]+=tag[o]; 
		tag[o]=0;
	}
}

inline void update(int o,int l,int r,int x,int y,int v)
{
	if(r<x||l>y) return;
	if(x<=l&&r<=y){
		tag[o]+=v;maxv[o]+=v;
		return; 
	}
	pushdown(o);
	int mid=(l+r)/2;
	update(o*2,l,mid,x,y,v);
	update(o*2+1,mid+1,r,x,y,v);
	maxv[o]=max(maxv[o*2],maxv[o*2+1]);
}

inline int query(int o,int l,int r,int x,int y)
{
	if(r<x||l>y) return -INF;
	if(x<=l&&r<=y) return maxv[o];
	pushdown(o);
	int mid=(l+r)/2,res=-INF;
	res=max(res,query(o*2,l,mid,x,y));
	res=max(res,query(o*2+1,mid+1,r,x,y));
	return res;
}

signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	long long ans=0ll;
	for(int i=1;i<=n;i++) ans-=1ll*a[i];
	for(int i=1;i<=n;i++) b[i]=make_pair(a[i],i);
	sort(b+1,b+n+1);reverse(b+1,b+n+1);
	build(1,1,n);
	for(int i=1;i<=n;i++){
		int val=b[i].first,id=b[i].second;
		if(query(1,1,n,id,n)<0){
			update(1,1,n,id,n,1);
			ans+=1ll*val; 
		}
		if(query(1,1,n,id,n)<0){
			update(1,1,n,id,n,1);
			ans+=1ll*val;
		}
	}
	cout<<ans<<'\n';
	return 0;
}