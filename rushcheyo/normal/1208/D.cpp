#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,p[200005],mnpos[1<<19];
ll s[200005],mn[1<<19],add[1<<19];

void pushup(int u){
	mn[u]=mn[u<<1|1],mnpos[u]=mnpos[u<<1|1];
	if(mn[u<<1]<mn[u])mn[u]=mn[u<<1],mnpos[u]=mnpos[u<<1];
}
void build(int u,int l,int r){
	if(l==r){mn[u]=s[l];mnpos[u]=l;return;}
	int mid=l+r>>1;
	build(u<<1,l,mid);
	build(u<<1|1,mid+1,r);
	pushup(u);
}
void upd(int u,ll v){
	add[u]+=v,mn[u]+=v;
}
void pushdown(int u){
	if(add[u]){
		upd(u<<1,add[u]);
		upd(u<<1|1,add[u]);
		add[u]=0;
	}
}
void update(int u,int l,int r,int ql,int qr,ll v){
	if(l>=ql&&r<=qr){upd(u,v);return;}
	int mid=l+r>>1;
	pushdown(u);
	if(ql<=mid)update(u<<1,l,mid,ql,qr,v);
	if(qr>mid)update(u<<1|1,mid+1,r,ql,qr,v);
	pushup(u);
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%lld",s+i);
	build(1,1,n);
	for(int i=1;i<=n;++i){
		int x=mnpos[1];
		p[x]=i;
		update(1,1,n,x,x,1LL<<40);
		if(x+1<=n)update(1,1,n,x+1,n,-i);
	}
	for(int i=1;i<=n;++i)printf("%d ",p[i]);
	puts("");
}