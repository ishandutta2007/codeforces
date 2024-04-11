#include <cstdio>
#define Maxn 200
int f[Maxn+5][Maxn+5];
int a[Maxn+5];
int head[Maxn+5],arrive[Maxn<<1|5],nxt[Maxn<<1|5],tot;
void add_edge(int from,int to){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
}
int n,k;
int mx(int a,int b){
	return a>b?a:b;
}
int mn(int a,int b){
	return a<b?a:b;
}
void dfs(int u,int fa){
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa){
			continue;
		}
		dfs(v,u);
	}
	int now;
	for(int i=k;i>0;i--){
		for(int j=head[u];j;j=nxt[j]){
			int v=arrive[j];
			if(v==fa){
				continue;
			}
			now=f[v][i-1];
			
			for(int l=head[u];l;l=nxt[l]){
				int to=arrive[l];
				if(to==fa||to==v){
					continue;
				}
				now+=f[to][mn(k,mx(k-i,i-1))];
			}
			f[u][i]=mx(f[u][i],now);
		}
		f[u][i]=mx(f[u][i],f[u][i+1]);
	}
	f[u][0]=a[u];
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa){
			continue;
		}
		f[u][0]+=f[v][k];
	}
	f[u][0]=mx(f[u][0],f[u][1]);
}
int main(){
	scanf("%d%d",&n,&k);
	int u,v;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<n;i++){
		scanf("%d%d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
	}
	dfs(1,0);
	printf("%d\n",f[1][0]);
	return 0;
}