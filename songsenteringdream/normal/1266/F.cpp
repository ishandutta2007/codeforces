#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
const int o=5e5+10;
int n,Fa[o],h[o],cnt,H[o*2],Cnt,ans[o*2],d[o],mx[o],mxd[o*5],tot,val;bool vis[o*5];vector<int> vec[o];
struct Edge{int v,p,w;}e[o*2],E[o*5];
inline void ad(int U,int V,int W){e[++cnt].v=V;e[cnt].p=h[U];e[h[U]=cnt].w=W;}
inline void Ad(int U,int V,int W){E[++Cnt].v=V;E[Cnt].p=H[U];E[H[U]=Cnt].w=W;}
void dfs(int nw,int fa){
	Fa[nw]=fa;
	for(int i=h[nw],j=nw;i;i=e[i].p) if(e[i].v^fa)
		Ad(j,++tot,0),Ad(tot,j,0),Ad(j=tot,e[i].v,1),Ad(e[i].v,j,1),dfs(e[i].v,nw);
}
void Dfs(int nw,int fa,bool flg){
	if(vis[nw]&&!flg) return;
	vis[nw]=1;mxd[nw]=E[nw].w;
	for(int i=H[E[nw].v];i;i=E[i].p) if(E[i].v^fa){
		Dfs(i,E[nw].v,flg&&!E[i].w);mxd[nw]=max(mxd[nw],mxd[i]+E[nw].w);
		if(flg&&E[i].w) vec[mxd[i]].push_back(val);
	}
}
int main(){
	scanf("%d",&n);tot=n;
	for(int i=1,u,v;i<n;++i) scanf("%d%d",&u,&v),ad(u,v,0),ad(v,u,0);
	dfs(1,0);
	for(int i=1;i<=n;++i) Ad(0,i,0),val=i,Dfs(Cnt,0,1);
	for(int i=n,lst,j;i;--i) for(lst=0,j=vec[i].size();j--;lst=vec[i][j]){
		++d[vec[i][j]];
		ans[2*i-1]=max(ans[2*i-1],d[vec[i][j]]);ans[2*i]=max(ans[2*i],d[vec[i][j]]);
		if(lst^vec[i][j]) ans[2*i+1]=max(ans[2*i+1],d[vec[i][j]]);
		if(Fa[vec[i][j]])
			ans[2*i]=max(ans[2*i],d[Fa[vec[i][j]]]+d[vec[i][j]]-2),mx[Fa[vec[i][j]]]=max(mx[Fa[vec[i][j]]],d[vec[i][j]]);
		ans[2*i]=max(ans[2*i],d[vec[i][j]]+mx[vec[i][j]]-2);
	}
	for(int i=1;i<=n;++i) ans[1]=max(ans[1],d[i]+1);
	for(int i=n*2;i;--i) ans[i]=max(ans[i],ans[i+2]);
	for(int i=1;i<=n;++i) printf("%d ",max(ans[i],1));
	return 0;
}