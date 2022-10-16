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
int max(int a,int b){
	return a>b?a:b;
}
const int Maxn=100000;
int n,ans;
int fa[Maxn+5];
int head[Maxn+5],arrive[Maxn<<1|5],nxt[Maxn<<1|5],tot;
void add_edge(int from,int to){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
}
int deg[Maxn+5];
struct Operation{
	int u,t;
}op[Maxn<<2|5];
int len;
void work_dfs(int u,int t){
	op[++len].u=u;
	op[len].t=t;
	int last=t;
	bool flag=0;
	if(last==ans){
		last=ans-deg[u];
		flag=1;
	}
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa[u]){
			continue;
		}
		fa[v]=u;
		if(flag){
			op[++len].u=u;
			op[len].t=last;
			flag=0;
		}
		work_dfs(v,++last);
		op[++len].u=u;
		op[len].t=last;
		if(last==ans){
			last=ans-deg[u];
			flag=1;
		}
	}
	if(flag){
		last=ans;
	}
	if(u!=1&&last!=t-1){
		op[++len].u=u;
		op[len].t=t-1;
	}
}
int main(){
	read(n);
	for(int i=1;i<n;i++){
		int u,v;
		read(u),read(v);
		add_edge(u,v);
		add_edge(v,u);
		deg[u]++,deg[v]++;
	}
	for(int i=1;i<=n;i++){
		ans=max(ans,deg[i]);
	}
	work_dfs(1,0);
	printf("%d\n",len);
	for(int i=1;i<=len;i++){
		printf("%d %d\n",op[i].u,op[i].t);
	}
	return 0;
}