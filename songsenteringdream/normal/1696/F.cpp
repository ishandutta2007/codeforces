#include<cstdio>
using namespace std;
const int o=110;
int T,n,d[o][o],h[o],cnt,x[o],y[o],m;bool a[o][o][o],vis[o],in[o],yny[o][o];char s[o];
struct Edge{int v,p;}e[o*2];
inline void ad(int U,int V){e[++cnt].v=V;e[cnt].p=h[U];h[U]=cnt;}
void dfs(int rt,int nw,int fa){
	for(int i=h[nw];i;i=e[i].p) if(e[i].v^fa) d[rt][e[i].v]=d[rt][nw]+1,dfs(rt,e[i].v,nw);
}
inline void ext(int nw,int u){
	if(vis[nw]) return;
	vis[nw]=1;
	for(int i=1;i<=n;++i) if(!in[i]&&a[i][u][nw]) in[i]=1,x[++m]=nw,y[m]=i;
}
inline void slv(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) a[i][i][j]=1;
	for(int i=1;i<n;++i) for(int j=1;j<=n-i;++j){
		scanf("%s",s+1);
		for(int k=1;k<=n;++k) a[i][i+j][k]=a[i+j][i][k]=s[k]-48;
	}
	for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) for(int k=yny[i][j]=1;k<=n;++k) yny[i][j]&=!a[i][j][k];
	for(int i=2,flg;i<=n;++i) if(yny[1][i]){
		for(int j=1;j<=n;++j) vis[j]=in[j]=h[j]=0;
		x[m=1]=1;y[1]=i;in[1]=in[i]=1;cnt=0;flg=1;
		for(int j=1;j<=m;++j) ext(x[j],y[j]),ext(y[j],x[j]);
		if(m<n-1) continue;
		for(int j=1;j<n;++j) ad(x[j],y[j]),ad(y[j],x[j]);
		for(int j=1;j<=n;++j) dfs(j,j,0);
		for(int j=1;j<n&&flg;++j) for(int k=j+1;k<=n&&flg;++k) for(int $=1;$<=n&&flg;++$) flg=(a[j][k][$]==(d[j][$]==d[k][$]));
		if(!flg) continue;
		printf("Yes\n");
		for(int j=1;j<n;++j) printf("%d %d\n",x[j],y[j]);
		return;
	}
	printf("No\n");
}
int main(){
	for(scanf("%d",&T);T--;) slv();
	return 0;
}