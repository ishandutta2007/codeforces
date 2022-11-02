#include<bits/stdc++.h>
#define N 100005
#define mid (l+r>>1)
#define chk if(l>rr||r<ll)return;if(l>=ll&&r<=rr)
using namespace std;
int n,q,f[N],siz[N],son[N],dfn[N],ad[N],top[N],sum[N*3],mx[N*3];
bool c[N*3];
int op,u,v,res,tmp;
inline void cov(int k,int l,int r){
	sum[k]=l-r-1,mx[k]=-1,c[k]=1;
}
inline void pd(int k,int l,int r){
    if(c[k])cov(k*2,l,mid),cov(k*2|1,mid+1,r),c[k]=0;
}
inline void upd(int k){
	sum[k]=sum[k*2]+sum[k*2|1];
	mx[k]=max(mx[k*2|1],mx[k*2]+sum[k*2|1]);
}
void qmax(int k,int l,int r,int ll,int rr){
	chk res=max(res,tmp+mx[k]),tmp+=sum[k];
	else pd(k,l,r),qmax(k*2|1,mid+1,r,ll,rr),qmax(k*2,l,mid,ll,rr);
}
void mdf(int k,int l,int r,int ll,int rr){
	chk cov(k,l,r);
	else pd(k,l,r),mdf(k*2,l,mid,ll,rr),mdf(k*2+1,mid+1,r,ll,rr),upd(k);
}
void pls(int k,int l,int r,int d,int v){
	if(l<r)pd(k,l,r),d>mid?pls(k*2|1,mid+1,r,d,v):pls(k*2,l,mid,d,v),upd(k);
	else mx[k]+=v,sum[k]+=v;
}
inline void cal(){
	res=-1,v=u,tmp=0;
	for(;v;v=v[top][f])
	qmax(1,1,n,v[top][dfn],dfn[v]);
}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=2;i<=n;i++)
	scanf("%d",f+i);
	for(int i=n;i;i--)
	siz[i]++,i>1?siz[f[i]]+=siz[i]:0,siz[son[f[i]]]<siz[i]?i[f][son]=i:0;
	for(int i=1;i<=n;i++)
	i[f][son]==i?top[i]=i[f][top],dfn[i]=dfn[f[i]]+1:
	(dfn[i]=i[f][dfn]+i[f][son][siz]+i[f][ad]+1,i[f][ad]+=siz[i],top[i]=i);
	for(cov(1,1,n);q--;){
		scanf("%d%d",&op,&u);
        if(op>2)cal(),puts(res<0?"white":"black");
        else if(op>1)
		mdf(1,1,n,dfn[u],dfn[u]+siz[u]-1),cal(),
		res>=0?pls(1,1,n,dfn[u],-res-1),0:0;
		else pls(1,1,n,dfn[u],1);
	}
}