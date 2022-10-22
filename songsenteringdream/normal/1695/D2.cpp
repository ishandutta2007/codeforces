#include<cstdio>
#include<iostream>
using namespace std;
const int o=4e5+10;
int T,n,d[o],f[o],ans,h[o],cnt;bool flg;
struct Edge{int v,p;}e[o];
inline void ad(int U,int V){e[++cnt].v=V;e[cnt].p=h[U];h[U]=cnt;}
void dfs(int nw,int fa){
	for(int i=h[nw];i;i=e[i].p) if(e[i].v^fa) dfs(e[i].v,nw),f[nw]+=f[e[i].v];
	cnt=0;
	for(int i=h[nw];i;i=e[i].p) if(e[i].v^fa) cnt+=!f[e[i].v];
	if(cnt) f[nw]+=cnt-1;
}
int main(){
	for(scanf("%d",&T);T--;printf("%d\n",ans),cnt=0){
		scanf("%d",&n);
		if(n==1){ans=0;continue;}
		for(int i=1;i<=n;++i) d[i]=f[i]=h[i]=0;
		for(int i=1,u,v;i<n;++i) scanf("%d%d",&u,&v),++d[u],++d[v],ad(u,v),ad(v,u);
		for(int i=flg=1;i<=n;++i) flg&=(d[i]<3);
		if(flg){ans=1;continue;}
		for(int i=1;i<=n;++i) if(d[i]>2){dfs(i,0);ans=f[i];break;}
	}
	return 0;
}