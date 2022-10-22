#include<bits/stdc++.h>
using namespace std;
#define MN 200005
#define LL long long
#define Ls (x<<1)
#define Rs (x<<1|1)
#define mid ((l+r)>>1)
LL Min[MN<<3],sum[MN],tag[MN<<3];
int n,p[MN],a[MN],loc[MN];
void build(int x,int l,int r){
	if(l==r){Min[x]=sum[l];return;}
	build(Ls,l,mid);
	build(Rs,mid+1,r);
	Min[x]=min(Min[Ls],Min[Rs]);
}
void pushdown(int x){
	if(tag[x]){
		Min[Ls]+=tag[x];
		Min[Rs]+=tag[x];
		tag[Ls]+=tag[x];
		tag[Rs]+=tag[x];
		tag[x]=0;
	}
}
void change(int x,int l,int r,int b,int e,int v){
	if(l>e||r<b)return;
	if(b<=l&&r<=e){Min[x]+=v;tag[x]+=v;return;}
	pushdown(x);
	change(Ls,l,mid,b,e,v);change(Rs,mid+1,r,b,e,v);
	Min[x]=min(Min[Ls],Min[Rs]);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){scanf("%d",&p[i]);loc[p[i]]=i;}
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	LL ans=min(a[1],a[n]);
	build(1,1,n-1);
	for(int i=1;i<n;++i){
		change(1,1,n-1,loc[i],n-1,-a[loc[i]]);
		if(loc[i]!=1)change(1,1,n-1,1,loc[i]-1,a[loc[i]]);
		ans=min(ans,Min[1]);
	}
	printf("%lld\n",ans);
}