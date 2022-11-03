#include<bits/stdc++.h>
using namespace std;

struct edge{
	int nxt,to;
}e[100005];
const int m=256;
int n,q,a[50005],cnt,b[50005][m],ft[50005],fa[50005],up[50005],dep[50005],go[5005][2];
void dfs(int x,int f){
	for(int i=ft[x];i;i=e[i].nxt)if(e[i].to!=f){
		int y=e[i].to;fa[y]=x;dep[y]=dep[x]+1;
		dfs(y,x);
	}
}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<n;i++){
		int x,y;scanf("%d%d",&x,&y);
		e[i<<1]=(edge){ft[x],y};ft[x]=i<<1;
		e[i<<1|1]=(edge){ft[y],x};ft[y]=i<<1|1;
	}
	dep[1]=1;dfs(1,0);
	for(int i=1;i<=n;i++){
		int k=i;
		for(int j=0;j<m;j++)k=fa[k];
		up[i]=k;
		if(k){
			int k=i;cnt=2;
			for(int j=0;j<m;j++){
				int now=1,p=a[k]^j;
				for(int k=15;k>=0;k--){
					bool f=p>>k&1;
					if(!go[now][f])go[now][f]=cnt++;
					now=go[now][f];
				}
				k=fa[k];
			}
			for(int j=0;j<m;j++){
				int p=j<<8,now=1,ans=0;
				for(int k=15;k>=0;k--){
					bool f=p>>k&1;
					if(go[now][!f])now=go[now][!f],ans|=1<<k;else now=go[now][f];
				}
				b[i][j]=ans;
			}
			for(int j=1;j<cnt;j++)go[j][0]=go[j][1]=0;
		}
	}
	while(q--){
		int u,v,v1,ans=0,j=0;scanf("%d%d",&u,&v);
		ans=a[u]^dep[v]-dep[u];v1=v;
		while(dep[v]>dep[u]+m){
			ans=max(ans,b[v][j++]);
			v=up[v];
		}
		for(;v!=u;v=fa[v])ans=max(ans,a[v]^dep[v1]-dep[v]);
		printf("%d\n",ans);
	}
	return 0;
}