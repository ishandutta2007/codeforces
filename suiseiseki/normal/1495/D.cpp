#include <cstdio>
#include <cstring>
#include <algorithm>
const int Maxn=400;
const int Maxm=600;
const int Mod=998244353;
int n,m;
int head[Maxn+5],arrive[Maxm<<1|5],nxt[Maxm<<1|5],tot;
void add_edge(int from,int to){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
}
int dis[Maxn+5][Maxn+5];
int qu[Maxn+5],qu_f,qu_t;
bool in[Maxn+5];
int cnt[Maxn+5];
int main(){
	scanf("%d%d",&n,&m);
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
		dis[u][v]=dis[v][u]=1;
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=std::min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			memset(in,0,sizeof in);
			int num=0;
			for(int k=1;k<=n;k++){
				if(dis[i][k]+dis[k][j]==dis[i][j]){
					num++;
					in[k]=1;
				}
			}
			if(num!=dis[i][j]+1){
				printf("0 ");
				continue;
			}
			qu_f=1,qu_t=0;
			memset(cnt,0,sizeof cnt);
			for(int k=1;k<=n;k++){
				if(in[k]){
					qu[++qu_t]=k;
				}
			}
			while(qu_f<=qu_t){
				int u=qu[qu_f++];
				for(int k=head[u];k;k=nxt[k]){
					int v=arrive[k];
					if(dis[i][u]+1==dis[i][v]&&dis[j][u]+1==dis[j][v]){
						cnt[v]++;
						if(!in[v]){
							in[v]=1;
							qu[++qu_t]=v;
						}
					}
				}
			}
			int ans=1;
			for(int k=1;k<=n;k++){
				if(dis[i][k]+dis[k][j]!=dis[i][j]){
					ans=1ll*ans*cnt[k]%Mod;
				}
			}
			printf("%d ",ans);
		}
		puts("");
	}
	return 0;
}