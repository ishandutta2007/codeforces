#include <cstdio>
#include <cstring>
#include <algorithm>
typedef long long ll;
const int Maxn=4000;
int n,m;
int root;
ll f[Maxn+5][Maxn+5];
int a[Maxn+5];
int st[Maxn+5],st_top;
int ch[Maxn+5][2];
int sz[Maxn+5];
void init_dfs(int u){
	if(ch[u][0]==0&&ch[u][1]==0){
		sz[u]=1;
		f[u][0]=0,f[u][1]=1ll*m*a[u]-a[u];
		return;
	}
	if(ch[u][0]==0||ch[u][1]==0){
		int v=ch[u][0]+ch[u][1];
		init_dfs(v);
		sz[u]=sz[v]+1;
		for(int i=0;i<=std::min(m,sz[v]);i++){
			f[u][i]=std::max(f[u][i],f[v][i]);
			f[u][i+1]=std::max(f[u][i+1],f[v][i]+1ll*m*a[u]-a[u]-2ll*i*a[u]);
		}
		return;
	}
	int v_1=ch[u][0],v_2=ch[u][1];
	init_dfs(v_1),init_dfs(v_2);
	sz[u]=sz[v_1]+sz[v_2]+1;
	for(int i=0;i<=std::min(m,sz[v_1]);i++){
		for(int j=0;j<=std::min(m,sz[v_2]);j++){
			f[u][i+j]=std::max(f[u][i+j],f[v_1][i]+f[v_2][j]-2ll*a[u]*i*j);
			f[u][i+j+1]=std::max(f[u][i+j+1],f[v_1][i]+f[v_2][j]+1ll*a[u]*m-a[u]-2ll*a[u]*i*j-2ll*(i+j)*a[u]);
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		while(st_top>0&&a[i]<a[st[st_top]]){
			ch[i][0]=st[st_top];
			st_top--;
		}
		if(st_top>0){
			ch[st[st_top]][1]=i;
		}
		st[++st_top]=i;
	}
	root=st[1];
	memset(f,-0x3f,sizeof f);
	init_dfs(root);
	printf("%lld\n",f[root][m]);
	return 0;
}