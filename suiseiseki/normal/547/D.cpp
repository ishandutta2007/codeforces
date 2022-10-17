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
const int Maxn=200000;
int n;
int head[Maxn<<1|5],arrive[Maxn<<2|5],nxt[Maxn<<2|5],tot;
void add_edge(int from,int to){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
}
int col[Maxn<<1|5];
int deg[Maxn<<1|5];
void dfs(int u){
	for(int& i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(col[(i+1)>>1]){
			continue;
		}
		col[(i+1)>>1]=1+(u<=Maxn);
		dfs(v);
	}
}
int main(){
	read(n);
	for(int i=1;i<=n;i++){
		int u,v;
		read(u),read(v);
		add_edge(u,v+Maxn);
		add_edge(v+Maxn,u);
		deg[u]++,deg[v+Maxn]++;
	}
	for(int i=1;i<=(Maxn<<1);i++){
		if(deg[i]&1){
			add_edge(i,(Maxn<<1|1));
			add_edge((Maxn<<1|1),i);
		}
	}
	for(int i=1;i<=Maxn;i++){
		dfs(i);
	}
	for(int i=1;i<=n;i++){
		if(col[i]==1){
			putchar('b');
		}
		else{
			putchar('r');
		}
	}
	puts("");
	return 0;
}