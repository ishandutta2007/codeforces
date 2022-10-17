#include <queue>
#include <cstdio>
#include <iostream>
using namespace std;
#define Maxn 200000
int n,k;
int head[Maxn+5],arrive[Maxn<<1|5],nxt[Maxn<<1|5],tot;
void add_edge(int from,int to){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
}
int c[Maxn+5];
bool vis[Maxn+5];
int dep[Maxn+5];
bool on[Maxn+5];
void dfs_1(int u,int fa){
	dep[u]=dep[fa]+1;
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa){
			continue;
		}
		dfs_1(v,u);
	}
}
void dfs_2(int u,int fa){
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa){
			continue;
		}
		dfs_2(v,u);
		if(on[v]){
			on[u]=1;
		}
	}
}
int s,t,mx_dep;
int maxn[2][Maxn+5];
void dfs_3(int u,int fa,bool tag){
	if(tag){
		c[u]=(c[fa]+1)%k;
	}
	else{
		c[u]=(c[fa]-1+k)%k;
	}
	maxn[0][u]=maxn[1][u]=0;
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa){
			continue;
		}
		dfs_3(v,u,tag);
		if(maxn[0][v]+1>maxn[0][u]){
			maxn[1][u]=maxn[0][u];
			maxn[0][u]=maxn[0][v]+1;
		}
		else if(maxn[0][v]+1>maxn[1][u]){
			maxn[1][u]=maxn[0][v]+1;
		}
	}
	if(maxn[0][u]&&maxn[1][u]&&maxn[0][u]+maxn[1][u]+1>=k){
		puts("No");
		exit(0);
	}
}
void dfs_4(int u,int fa){
	c[u]=(c[fa]+1)%k;
	maxn[0][u]=maxn[1][u]=0;
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa){
			continue;
		}
		if(on[v]){
			dfs_4(v,u);
		}
		else{
			if(dep[u]<=mx_dep-dep[u]+1){
				dfs_3(v,u,0);
			}
			else{
				dfs_3(v,u,1);
			}
			if(maxn[0][v]+1>maxn[0][u]){
				maxn[1][u]=maxn[0][u];
				maxn[0][u]=maxn[0][v]+1;
			}
			else if(maxn[0][v]+1>maxn[1][u]){
				maxn[1][u]=maxn[0][v]+1;
			}
		}
	}
	if(maxn[0][u]&&maxn[1][u]&&maxn[0][u]+maxn[1][u]+1>=k){
		puts("No");
		exit(0);
	}
	if(maxn[0][u]&&dep[u]+maxn[0][u]>=k&&maxn[0][u]+mx_dep-dep[u]+1>=k){
		puts("No");
		exit(0);
	}
}
int main(){
	scanf("%d%d",&n,&k);
	int u,v;
	for(int i=1;i<n;i++){
		scanf("%d%d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
	}
	if(k==2){
		queue<int> q;
		q.push(1);
		c[1]=0;
		vis[1]=1;
		while(!q.empty()){
			int u=q.front();
			q.pop();
			for(int i=head[u];i;i=nxt[i]){
				int v=arrive[i];
				if(vis[v]){
					continue;
				}
				c[v]=(c[u]^1);
				vis[v]=1;
				q.push(v);
			}
		}
		puts("Yes");
		for(int i=1;i<=n;i++){
			printf("%d ",c[i]+1);
		}
		puts("");
		return 0;
	}
	dfs_1(1,0);
	for(int i=1;i<=n;i++){
		if(dep[i]>dep[s]){
			s=i;
		}
	}
	dfs_1(s,0);
	for(int i=1;i<=n;i++){
		if(dep[i]>mx_dep){
			mx_dep=dep[i];
			t=i;
		}
	}
	on[t]=1;
	dfs_2(s,0);
	c[0]=k-1;
	dfs_4(s,0);
	puts("Yes");
	for(int i=1;i<=n;i++){
		printf("%d ",c[i]+1);
	}
	puts("");
	return 0;
}