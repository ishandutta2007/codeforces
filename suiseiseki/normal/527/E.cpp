#include <cstdio>
void read(int &a){
	a=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		a=(a<<1)+(a<<3)+(c^48);
		c=getchar();
	}
}
const int Maxn=100000;
const int Maxm=300000;
int num;
bool vis[Maxm<<1|5];
int head[Maxn+5],arrive[Maxm<<1|5],nxt[Maxm<<1|5],tot;
int deg[Maxn+5];
void add_edge(int from,int to){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
}
int n,m;
int lis[Maxn+5],lis_len;
void dfs(int u){
	for(int &i=head[u];i;i=nxt[i]){
		if(vis[i]){
			continue;
		}
		int v=arrive[i];
		vis[i]=vis[((i-1)^1)+1]=1;
		dfs(v);
		num++;
		if(num&1){
			printf("%d %d\n",u,v);
		}
		else{
			printf("%d %d\n",v,u);
		}
	}
}
int main(){
	read(n),read(m);
	int u,v;
	for(int i=1;i<=m;i++){
		read(u),read(v);
		add_edge(u,v);
		add_edge(v,u);
		deg[u]++;
		deg[v]++;
	}
	for(int i=1;i<=n;i++){
		if(deg[i]&1){
			lis[++lis_len]=i;
		}
	}
	for(int i=1;i<=lis_len;i+=2){
		add_edge(lis[i],lis[i+1]);
		add_edge(lis[i+1],lis[i]);
		m++;
	}
	if(m&1){
		m++;
		add_edge(1,1);
		add_edge(1,1);
	}
	printf("%d\n",m);
	dfs(1);
	return 0;
}