#include<cstdio>
#include<iostream>
using namespace std;
const int o=2e5+10;
int T,n,h[o],cnt,d[o],mxd,sn[o];
struct Edge{int v,p;}e[o];
inline void ad(int U,int V){e[++cnt].v=V;e[cnt].p=h[U];h[U]=cnt;}
void dfs(int nw,int fa){
	mxd=max(mxd,d[nw]=d[fa]+1);
	for(int i=h[nw];i;i=e[i].p) if(e[i].v^fa) dfs(e[i].v,nw),++sn[nw];
	if(nw<2) --sn[nw];
}
int main(){
	for(scanf("%d",&T);T--;putchar('\n'),cnt=mxd=0){
		scanf("%d",&n);
		for(int i=1;i<=n;++i) h[i]=sn[i]=0;
		for(int i=1,u,v;i<n;++i) scanf("%d%d",&u,&v),ad(u,v),ad(v,u);
		dfs(1,0);
		for(int i=1;i<=n;++i) if((d[i]&1)==(mxd&1)) printf("%d ",1+sn[i]);else printf("%d ",-1-sn[i]);
	}
	return 0;
}