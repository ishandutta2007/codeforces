#include<bits/stdc++.h>
#define mi (l+r>>1)
const int N=300005,V=N*20;
using namespace std;
typedef long long ll;
const ll inf=1e17;
int n,m,to[N*3],hd[N*3],lk[N*2],ln[N*3],cnt,
de[N],rt[N],ls[V],rs[V],tot;
ll sum[N],mn[V],ad[V];
inline void add(int u,int v){
	to[++cnt]=v,hd[cnt]=lk[u],lk[u]=cnt;
}int u,v,w;
inline void pls(int x,ll v){
	mn[x]+=v,ad[x]+=v;
}
inline void pd(int x){
	pls(ls[x],ad[x]),pls(rs[x],ad[x]),ad[x]=0;
}
void ins(int&x,int l,int r,int d,ll v){
	if(!x)x=++tot,mn[x]=inf;
	if(l<r)d>mi?
	ins(rs[x],mi+1,r,d,v):ins(ls[x],l,mi,d,v);
	mn[x]=min(mn[x],v);
}
void uni(int&x,int y){
	if(x&&y)
	pd(x),pd(y),
	uni(ls[x],ls[y]),uni(rs[x],rs[y]),
	mn[x]=min(mn[x],mn[y]);
	else x|=y;
}
ll qry(int x,int l,int r,int d){
	if(l>d||!x)return inf;
	if(r<=d)return mn[x];
	pd(x);
	return min(qry(ls[x],l,mi,d),qry(rs[x],mi+1,r,d));
}
inline void deb(int x,int l,int r){
	if(!x)return;
	cerr<<'['<<l<<','<<r<<']'<<mn[x]<<'('<<ad[x]<<")\n";
	deb(ls[x],l,mi),deb(rs[x],mi+1,r);
}
void dfs(int x,int y){
	ll tp=0;
	for(int s,i=lk[x];i;i=hd[i])
	if((s=to[i])^y)
	de[s]=de[x]+1,dfs(s,x),tp+=sum[s];
	//cerr<<"cal "<<x<<'('<<tp<<endl;
	for(int i=lk[x+n];i;i=hd[i])
	//cerr<<"~"<<to[i]<<'/'<<de[to[i]]<<endl,
	ins(rt[x],0,n-1,de[to[i]],tp+ln[i]);
	for(int s,i=lk[x];i;i=hd[i])
	if((s=to[i])^y)
	pls(rt[s],tp-sum[s]),
	uni(rt[x],rt[s]);
	sum[x]=qry(rt[x],0,n-1,de[y]);
	//deb(rt[x],0,n-1);
	if(sum[x]>=inf)puts("-1"),exit(0);
}
int main(){
	//freopen("dat.txt","r",stdin);
	scanf("%d%d",&n,&m);
	if(n<2)return puts("0"),0;
	for(int i=1;i<n;i++)
	scanf("%d%d",&u,&v),
	add(u,v),add(v,u);
	for(;m--;)
	scanf("%d%d%d",&u,&v,&w),
	add(u+n,v),ln[cnt]=w;
	cnt=0,dfs(1,0);
	printf("%lld",sum[1]);
}