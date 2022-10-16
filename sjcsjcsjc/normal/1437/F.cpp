#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define MOD 998244353
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

int n,a[5010],dp[5010][40];
int _n,sumv[20010],tag[20010];

inline void init(int x)
{
	_n=1;
	while(_n<x) _n*=2;
	for(int i=_n;i<2*_n;i++){
		sumv[i]=1;tag[i]=1;
	}
	for(int i=_n-1;i>=1;i--){
		sumv[i]=sumv[i*2]+sumv[i*2+1];
		tag[i]=1;
	}
}

inline void pushdown(int o,int l,int r)
{
	int lc=o*2,rc=o*2+1;
	if(r>l){
		tag[lc]=(1ll*tag[lc]*tag[o])%MOD; 
		sumv[lc]=(1ll*sumv[lc]*tag[o])%MOD;
		tag[rc]=(1ll*tag[rc]*tag[o])%MOD;
		sumv[rc]=(1ll*sumv[rc]*tag[o])%MOD;
		tag[o]=1;
	}
}

inline void pushup(int o,int l,int r)
{
	int lc=o*2,rc=o*2+1;
	if(r>l){
		sumv[o]=(sumv[lc]+sumv[rc])%MOD;
	} 
}

inline void update(int o,int l,int r,int x,int y,int v)
{
	if(r<x||l>y) return;
	if(x<=l&&r<=y){
		tag[o]=(1ll*v*tag[o])%MOD;
		sumv[o]=(1ll*v*sumv[o])%MOD;
		return;
	}
	pushdown(o,l,r);
	int mid=(l+r)/2;
	update(o*2,l,mid,x,y,v);
	update(o*2+1,mid+1,r,x,y,v);
	pushup(o,l,r);
}

inline int query(int o,int l,int r,int x,int y)
{
	if(r<x||l>y) return 0;
	if(x<=l&&r<=y){
		return sumv[o];
	}
	pushdown(o,l,r);
	int sum=0,mid=(l+r)/2;
	sum=(sum+query(o*2,l,mid,x,y))%MOD;
	sum=(sum+query(o*2+1,mid+1,r,x,y))%MOD;
	return sum;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);reverse(a+1,a+n+1);
	dp[1][1]=1;
	int ans=0;
	for(int i=2;i<=35;i++){
		init(n);
		for(int j=1;j<=n;j++){
			int l=1,r=j,pos=0;
			while(l<=r){
				int mid=(l+r)/2;
				if(a[mid]>=2*a[j]){
					pos=mid;
					l=mid+1;
				}
				else r=mid-1;
			}
			if(pos==0) dp[j][i]=0;
			else dp[j][i]=query(1,1,_n,1,pos);
			update(1,1,_n,j,j,dp[j][i-1]);
			if(pos>0) update(1,1,_n,1,pos,j-1);
			if(j>pos+1) update(1,1,_n,pos+1,j-1,j-2);
		}
		ans=(ans+query(1,1,_n,1,n))%MOD;
	}
	cout<<ans<<endl;
	return 0;
}