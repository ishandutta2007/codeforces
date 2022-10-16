#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define INF 1000000007
using namespace __gnu_pbds;
using namespace std;

int n,a[100010];
int maxv[400010],addv[400010],cnt[400010];

inline void build(int o,int l,int r)
{
	maxv[o]=-INF;cnt[o]=r-l+1;
	int mid=(l+r)/2;
	if(r>l){
		build(o*2,l,mid);
		build(o*2+1,mid+1,r);
	}
}

inline void pushdown(int o)
{
	addv[o*2]+=addv[o];addv[o*2+1]+=addv[o];
	maxv[o*2]+=addv[o];maxv[o*2+1]+=addv[o];
	addv[o]=0; 
}

inline void pushup(int o)
{
	maxv[o]=max(maxv[o*2],maxv[o*2+1]);
	cnt[o]=0;
	if(maxv[o]==maxv[o*2]) cnt[o]+=cnt[o*2];
	if(maxv[o]==maxv[o*2+1]) cnt[o]+=cnt[o*2+1];
}

inline void update(int o,int l,int r,int x,int y,int v)
{
	if(x<=l&&r<=y){
		addv[o]+=v;maxv[o]+=v;
		return;
	}
	if(r<x||l>y) return;
	pushdown(o);
	int mid=(l+r)/2;
	update(o*2,l,mid,x,y,v);
	update(o*2+1,mid+1,r,x,y,v);
	pushup(o); 
}

inline pair<int,int> query(int o,int l,int r,int x,int y)
{
	if(x<=l&&r<=y) return make_pair(maxv[o],cnt[o]);
	if(r<x||l>y) return make_pair(-INF,0);
	pair<int,int> res=make_pair(-INF,0);
	pushdown(o);
	int mid=(l+r)/2;
	pair<int,int> val1=query(o*2,l,mid,x,y);
	pair<int,int> val2=query(o*2+1,mid+1,r,x,y);
	if(val1.first>res.first) res=val1;
	else res.second+=val1.second;
	if(val2.first>res.first) res=val2;
	else res.second+=val2.second;
	return res;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	build(1,1,n+1);
	update(1,1,n+1,n+1,n+1,1-query(1,1,n+1,n+1,n+1).first);
	for(int i=2;i<=n;i++){
		pair<int,int> now=query(1,1,n+1,1,n+1);
		int pre=query(1,1,n+1,a[i-1],a[i-1]).first,cur;
		if(now.second==1&&query(1,1,n+1,a[i],a[i]).first==now.first){
			update(1,1,n+1,a[i-1],a[i-1],now.first-pre);
			cur=now.first;
		}
		else{
			update(1,1,n+1,a[i-1],a[i-1],now.first+1-pre);
			cur=now.first+1;
		}
		if(a[i-1]!=a[i]){
			if(pre+1<=cur) update(1,1,n+1,a[i-1],a[i-1],-1);
			update(1,1,n+1,1,n+1,1);
		}
	}
	cout<<query(1,1,n+1,1,n+1).first<<endl;
	return 0;
}