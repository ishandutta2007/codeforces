#include <cstdio>
#include <cstring>
#include <algorithm>
typedef long long ll;
const int Maxn=600;
const int Maxm=Maxn*Maxn;
int n,m,q;
int mp[Maxn+5][Maxn+5];
ll f[Maxn+5][Maxn+5];
ll g[Maxn+5][Maxn+5];
struct Question{
	int u,v,l;
}qu[Maxm+5];
int main(){
	scanf("%d%d",&n,&m);
	memset(mp,-1,sizeof mp);
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		mp[u][v]=mp[v][u]=f[u][v]=f[v][u]=w;
	}
	for(int i=1;i<=n;i++){
		f[i][i]=0;
	}
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		scanf("%d%d%d",&qu[i].u,&qu[i].v,&qu[i].l);
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=std::min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	int ans=0;
	for(int x=1;x<=n;x++){
		for(int u=1;u<=n;u++){
			for(int y=1;y<=n;y++){
				g[y][u]-=f[x][u];
			}
		}
		for(int y=1;y<=n;y++){
			if(mp[x][y]==-1){
				continue;
			}
			for(int u=1;u<=n;u++){
				if(g[y][u]>=mp[x][y]){
					ans++;
					break;
				}
			}
		}
		for(int u=1;u<=n;u++){
			for(int y=1;y<=n;y++){
				g[y][u]+=f[x][u];
			}
		}
		for(int i=1;i<=q;i++){
			g[x][qu[i].v]=std::max(g[x][qu[i].v],qu[i].l-f[x][qu[i].u]);
			g[x][qu[i].u]=std::max(g[x][qu[i].u],qu[i].l-f[x][qu[i].v]);
		}
	}
	printf("%d\n",ans);
	return 0;
}