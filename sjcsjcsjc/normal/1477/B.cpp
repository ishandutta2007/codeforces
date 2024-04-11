#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

int n,q,l[200010],r[200010],sum[800010],tag[800010];
char a[200010],b[200010];

inline void build(int o,int l,int r)
{
	tag[o]=-1;
	if(l==r){
		if(b[l]=='0') sum[o]=0;
		else sum[o]=1;
	}
	int mid=(l+r)/2;
	if(r>l){
		build(o*2,l,mid);
		build(o*2+1,mid+1,r);
		sum[o]=sum[o*2]+sum[o*2+1];
	}
}

inline void pushdown(int o,int l,int r)
{
	if(tag[o]!=-1){
		tag[o*2]=tag[o];tag[o*2+1]=tag[o];
		int mid=(l+r)/2;
		sum[o*2]=tag[o]*(mid-l+1);sum[o*2+1]=tag[o]*(r-mid);
		tag[o]=-1;
	}
}

inline void pushup(int o)
{
	sum[o]=sum[o*2]+sum[o*2+1];
}

inline void update(int o,int l,int r,int x,int y,int v)
{
	if(r<x||l>y) return;
	if(x<=l&&r<=y){
		tag[o]=v;sum[o]=v*(r-l+1);
		return;
	}
	pushdown(o,l,r);
	int mid=(l+r)/2;
	update(o*2,l,mid,x,y,v);
	update(o*2+1,mid+1,r,x,y,v);
	pushup(o);
}

inline int query(int o,int l,int r,int x,int y)
{
	if(r<x||l>y) return 0;
	if(x<=l&&r<=y) return sum[o];
	pushdown(o,l,r);
	int mid=(l+r)/2,res=0;
	res+=query(o*2,l,mid,x,y);
	res+=query(o*2+1,mid+1,r,x,y);
	return res;
} 

signed main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		cin>>n>>q;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++) cin>>b[i];
		for(int i=1;i<=q;i++) cin>>l[i]>>r[i];
		build(1,1,n);
		bool flag=true;
		for(int i=q;i>=1;i--){
			int val=query(1,1,n,l[i],r[i]);
			int zero=r[i]-l[i]+1-val,one=val;
			if(zero==one){
				flag=false;break;
			}
			else if(zero<one){
				update(1,1,n,l[i],r[i],1);
			}
			else{
				update(1,1,n,l[i],r[i],0);
			}
		}
		if(!flag){
			cout<<"NO\n";
			continue;
		}
		for(int i=1;i<=n;i++){
			int val=query(1,1,n,i,i);
			if(a[i]-'0'!=val){
				flag=false;break;
			}
		}
		if(!flag){
			cout<<"NO\n";
			continue;
		}
		cout<<"YES\n";
	}
	return 0;
}