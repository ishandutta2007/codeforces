#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define LL long long
#define M 300020
using namespace std;
LL read(){
	LL nm=0,fh=1;char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) if(cw=='-') fh=-fh;
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return nm*fh;
}
LL n,m,dep[M],val[M],dst[M],fs[M],nt[M],to[M];
LL fa[M][20],t[M][20],tmp,len,f[M],od[M],dfn[M],cnt,ans;
void link(LL x,LL y){nt[tmp]=fs[x],fs[x]=tmp,to[tmp++]=y;}
bool cmp(LL x,LL y){return dfn[x]>dfn[y];}
LL fd(LL x){return f[x]==x?x:(f[x]=fd(f[x]));}
void dfs(LL x){
	if(val[x]>m){puts("-1");exit(0);}
	dfn[x]=++cnt,dep[x]=dep[fa[x][0]]+1;
	for(LL j=1;j<20;j++) fa[x][j]=fa[fa[x][j-1]][j-1],t[x][j]=t[x][j-1]+t[fa[x][j-1]][j-1]-val[fa[x][j-1]];
	for(LL i=fs[x];i!=-1;i=nt[i]) dfs(to[i]);
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(),len=read(),m=read(),memset(fs,-1,sizeof(fs));
	for(LL i=1;i<=n;i++) val[i]=read(),f[i]=i,od[i]=i;
	for(LL i=2;i<=n;i++) fa[i][0]=read(),t[i][0]=val[i]+val[fa[i][0]],link(fa[i][0],i);
	dfs(1),sort(od+1,od+n+1,cmp);
	for(LL i=1;i<=n;i++){
		LL x=od[i],now=od[i],res=val[od[i]];
		if(fd(x)!=x) continue; ans++;
		for(LL j=19;j>=0;j--){
			if(!fa[now][j]) continue;
			if((dep[x]-dep[fa[now][j]]+1)<=len&&res+t[now][j]-val[now]<=m){
				res+=t[now][j]-val[now],now=fa[now][j];
			}
		}
		for(;x&&dep[x]>=dep[now];x=fd(fa[x][0])) f[x]=fd(fa[x][0]);
	}
	printf("%lld\n",ans);
	return 0;
}