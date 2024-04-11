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

int a[100010],l[100010],dp[100010],maxv[400010],X;

inline void build(int o,int l,int r)
{
	maxv[o]=0;
	if(l<r){
		int mid=(l+r)/2;
		build(o*2,l,mid);
		build(o*2+1,mid+1,r);
	}
}

inline void update(int o,int l,int r,int x,int v)
{
	if(r<x||l>x) return;
	if(x<=l&&r<=x){
		maxv[o]=v;
		return;
	}
	int mid=(l+r)/2;
	update(o*2,l,mid,x,v);
	update(o*2+1,mid+1,r,x,v);
	maxv[o]=max(maxv[o*2],maxv[o*2+1]);
}

inline int query(int o,int l,int r,int x,int y)
{
	if(r<x||l>y) return 0;
	if(x<=l&&r<=y) return maxv[o];
	int mid=(l+r)/2,res=0;
	res=max(res,query(o*2,l,mid,x,y));
	res=max(res,query(o*2+1,mid+1,r,x,y));
	return res;
}

signed main()
{
	ios::sync_with_stdio(false);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		cin>>X;
		l[1]=1;
		for(int i=2;i<=n;i++){
			if(a[i-1]+a[i]<2*X) l[i]=i;
			else if(i>=3&&a[i-2]+a[i-1]+a[i]<3*X) l[i]=i-1;
			else l[i]=l[i-1];
		}
		build(1,0,n+1);
		dp[0]=0;update(1,0,n+1,0,dp[0]+n+1);
		dp[1]=0;update(1,0,n+1,1,dp[1]+n);
		for(int i=2;i<=n+1;i++){
			dp[i]=dp[i-1];
			dp[i]=max(dp[i],query(1,0,n+1,l[i-1]-1,i-2)-(n+2-i));
			update(1,0,n+1,i,dp[i]+n+1-i);
		}
		cout<<dp[n+1]<<'\n';
	}
	return 0;
}