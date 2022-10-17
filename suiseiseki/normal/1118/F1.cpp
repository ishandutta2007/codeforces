#include <cstdio>
#include <algorithm>
using namespace std;
#define Maxn 300000
int a[Maxn+5];
int head[Maxn+5],arrive[Maxn<<1|5],nxt[Maxn<<1|5],tot;
void add_edge(int from,int to){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
}
int b[4];
int ans;
int f[Maxn+5][4];
void dfs(int root,int father){
	f[root][a[root]]=1;
	for(int i=head[root];i;i=nxt[i]){
		if(arrive[i]==father){
			continue;
		}
		dfs(arrive[i],root);
		f[root][1]+=f[arrive[i]][1];
		f[root][2]+=f[arrive[i]][2];
	}
	if((f[root][1]==0&&f[root][2]==b[2])||(f[root][2]==0&&f[root][1]==b[1])){
		ans++;
	}
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[a[i]]++;
	}
	int u,v;
	for(int i=1;i<n;i++){
		scanf("%d%d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
	}
	dfs(1,0);
	printf("%d\n",ans);
	return 0;
}