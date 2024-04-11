#include <cstdio>
#include <cstring>
#include <algorithm>
typedef long long ll;
const int Maxn=100;
const int Inf=0x3f3f3f3f;
int n,m,k;
bool g[Maxn+5][Maxn+5];
int to[Maxn+5];
bool vis[Maxn+5];
int lis[Maxn+5],len[Maxn+5];
ll f[Maxn+5][Maxn+5];
int pre[Maxn+5][Maxn+5];
struct Node{
	int x,y;
}a[Maxn+5];
bool match_dfs(int u){
	vis[u]=1;
	for(int v=n+1;v<=(n<<1);v++){
		if(g[u][v]&&!vis[v]){
			vis[v]=1;
			if(to[v]==0||match_dfs(to[v])){
				to[v]=u,to[u]=v;
				return 1;
			}
		}
	}
	return 0;
}
void work_dfs(int u){
	vis[u]=1;
	for(int v=n+1;v<=(n<<1);v++){
		if(g[u][v]&&!vis[v]){
			vis[v]=1;
			if(to[v]){
				work_dfs(to[v]);
			}
		}
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u][v+n]=1;
	}
	for(int i=1;i<=k;i++){
		scanf("%d%d",&a[i].x,&a[i].y);
	}
	for(int u=1;u<=n;u++){
		if(to[u]==0){
			memset(vis,0,sizeof vis);
			match_dfs(u);
		}
	}
	memset(vis,0,sizeof vis);
	for(int u=1;u<=n;u++){
		if(to[u]==0&&!vis[u]){
			work_dfs(u);
		}
	}
	int ans=0;
	for(int u=1;u<=n;u++){
		if(!vis[u]){
			lis[++ans]=u;
		}
	}
	for(int u=n+1;u<=(n<<1);u++){
		if(vis[u]){
			lis[++ans]=u;
		}
	}
	if(k<n-ans){
		printf("%d\n",k);
		for(int i=1;i<=k;i++){
			printf("0 ");
		}
		puts("");
		return 0;
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			f[i][j]=-Inf;
		}
	}
	f[0][0]=0;
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			for(int k=0;k<=n;k++){
				if(i>=n-ans+j+k){
					continue;
				}
				if(f[i-1][j]+std::max(0ll,a[i].x-1ll*a[i].y*k)>f[i][j+k]){
					f[i][j+k]=f[i-1][j]+std::max(0ll,a[i].x-1ll*a[i].y*k);
					pre[i][j+k]=k;
				}
			}
		}
	}
	printf("%d\n",k+(k+ans-n+1));
	for(int i=k,y=k+ans-n+1;i;i--){
		len[i]=pre[i][y];
		y-=pre[i][y];
	}
	for(int i=1,id=0;i<=k;i++){
		for(int j=1;j<=len[i];j++){
			printf("%d ",(lis[++id]>n?-(lis[id]-n):lis[id]));
		}
		printf("0 ");
	}
	puts("");
	return 0;
}