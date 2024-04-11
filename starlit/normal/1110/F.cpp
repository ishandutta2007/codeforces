#include<bits/stdc++.h>
#define mi (l+r>>1)
const int N=500005,V=10000000;
using namespace std;
typedef long long ll;
int n,q,ln[N],f[N],c[V][2],Rt[N],
ql[N],qr[N],dfn[N],sz[N],rt,cnt,cct;
ll ans[N],mn[V],ad[V];
vector<int>qu[N],ed[N];
inline void upd(int x){
	mn[x]=min(mn[c[x][0]],mn[c[x][1]]);
}
inline void cre(int&x){
	if(!x)x=++cnt,c[x][0]=c[x][1]=mn[x]=ad[x]=0;
}
inline void pls(int x,ll y){
	if(x)ad[x]+=y,mn[x]+=y;
}
inline void pd(int x){
	if(ad[x])
	pls(c[x][0],ad[x]),
	pls(c[x][1],ad[x]),ad[x]=0;
}
void ins(int&x,int l,int r,int d){
	cre(x);
	if(l<r){
		pd(x);
		if(d>mi)ins(c[x][1],mi+1,r,d);
		else ins(c[x][0],l,mi,d);
		upd(x);
	}
}
void mdf(int x,int l,int r,int L,int R,int v){
	if(l>R||r<L||!x)return;
	if(l>=L&&r<=R)return pls(x,v);
	pd(x);
	mdf(c[x][0],l,mi,L,R,v);
	mdf(c[x][1],mi+1,r,L,R,v);
	upd(x);
}
ll qry(int x,int l,int r,int L,int R){
	if(l>R||r<L||!x)return 1e18;
	if(l>=L&&r<=R)return mn[x];
	pd(x);
	return min(qry(c[x][0],l,mi,L,R),
	qry(c[x][1],mi+1,r,L,R));
}
void dfs(int x){
	sz[x]=1,dfn[x]=++cct;
	mdf(rt,1,n,1,dfn[x]-1,ln[x]);
	if(!ed[x].size())
	ins(rt,1,n,dfn[x]);
	for(int i:qu[x])
	ans[i]=min(ans[i],qry(rt,1,n,ql[i],qr[i]));
	for(int i=0,s;i<ed[x].size();i++)
	dfs(s=ed[x][i]),sz[x]+=sz[s];
	mdf(rt,1,n,1,dfn[x]-1,-ln[x]);
	mdf(rt,1,n,dfn[x],n,ln[x]);
}
void dfss(int x){
	mdf(rt,1,n,dfn[x]+sz[x],n,ln[x]);
	if(!ed[x].size())
	ins(rt,1,n,dfn[x]);
	for(int i:qu[x])
	ans[i]=min(ans[i],qry(rt,1,n,ql[i],qr[i]));
	for(int i=ed[x].size()-1;~i;i--)
	dfss(ed[x][i]);
	mdf(rt,1,n,dfn[x]+sz[x],n,-ln[x]);
	mdf(rt,1,n,1,dfn[x]+sz[x]-1,ln[x]);
}
void uni(int&x,int y){
	if(x&&y){
		pd(x),pd(y);
		uni(c[x][0],c[y][0]);
		uni(c[x][1],c[y][1]);
		upd(x);
	}
	else x|=y;
}
void ssfd(int x){
	if(!ed[x].size())
	ins(Rt[x],1,n,dfn[x]);
	for(int i=0,s;i<ed[x].size();i++)
	ssfd(s=ed[x][i]),uni(Rt[x],Rt[s]);
	for(int i:qu[x])
	ans[i]=min(ans[i],qry(Rt[x],1,n,ql[i],qr[i]));
	pls(Rt[x],ln[x]);
}
int x;
int main(){
	//freopen("dat.txt","r",stdin);
	scanf("%d%d",&n,&q);
	mn[0]=1e18;
	for(int i=2;i<=n;i++)
	scanf("%d%d",f+i,ln+i),
	ed[f[i]].push_back(i);
	for(int i=0;i<q;i++)
	ans[i]=1e18,scanf("%d%d%d",&x,ql+i,qr+i),
	qu[x].push_back(i);
	dfs(1);
	//cerr<<"i'm ready..\n";
	cnt=rt=0,dfss(1);
	//cerr<<"to count the stages..\n";
	cnt=0,ssfd(1);
	//cerr<<"to infinity..\n";
	for(int i=0;i<q;i++)
	printf("%lld\n",ans[i]);
}