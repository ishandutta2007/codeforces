#include<cstdio>
#include<vector>
using namespace std;
const int o=2010;
int n,p,f[o][o],d[o][o],s[o][o],c[o][o],pre[o][o],suf[o][o],ans[o];vector<int> e[o];
void dfs(int nw,int fa){
	for(int i=1;i<=n;++i) d[nw][i]=1;
	for(int i=0,sz=e[nw].size(),v,j;i<sz;++i) if((v=e[nw][i])^fa)
		for(dfs(v,nw),j=1;j<=n;++j) pre[v][j]=d[nw][j],d[nw][j]=d[nw][j]*1ll*s[v][j]%p;
	for(int i=1;i<=n;++i) f[nw][i]=d[nw][i],d[nw][i]=1;
	for(int i=e[nw].size(),v;i--;) if((v=e[nw][i])^fa)
		for(int j=1;j<=n;++j) suf[v][j]=d[nw][j],d[nw][j]=d[nw][j]*1ll*s[v][j]%p;
	if(nw==1) return;
	for(int i=e[nw].size(),v;i--;) if((v=e[nw][i])^fa) for(int j=1,sm=0;j<=n;++j)
		f[nw][j]=(f[nw][j]+f[v][j]*1ll*sm)%p,sm=(sm+pre[v][j]*1ll*suf[v][j])%p;
	for(int i=1;i<=n;++i) s[nw][i]=(s[nw][i-1]+f[nw][i])%p;
}
int main(){
	scanf("%d%d",&n,&p);
	for(int i=c[0][0]=1;i<=n;++i) for(int j=c[i][0]=1;j<=i;++j) c[i][j]=(c[i-1][j-1]+c[i-1][j])%p;
	for(int i=1,u,v;i<n;++i) scanf("%d%d",&u,&v),e[u].push_back(v),e[v].push_back(u);
	dfs(1,0);
	for(int i=1,j;i<=n;++i) for(ans[i]=f[1][i],j=1;j<i;++j) ans[i]=(ans[i]+(p-c[i][j])*1ll*ans[j])%p;
	for(int i=1;i<n;++i) printf("%d ",ans[i]);
	return 0;
}