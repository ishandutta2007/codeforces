#include <cstdio>
#include <algorithm>
using namespace std;
#define Maxn 100000
int head[Maxn+5],arrive[Maxn+5],nxt[Maxn+5],tot;
int f[Maxn+5];
void add_edge(int from,int to){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
}
void dfs(int root){
	f[root]=0;
	for(int i=head[root];i;i=nxt[i]){
		dfs(arrive[i]);
		f[root]+=f[arrive[i]];
	}
	if(f[root]==0){
		f[root]=1;
	}
}
int main(){
	int n;
	scanf("%d",&n);
	int fa;
	for(int i=2;i<=n;i++){
		scanf("%d",&fa);
		add_edge(fa,i);
	}
	dfs(1);
	sort(f+1,f+1+n);
	int ans=0;
	for(int i=1;i<=n;i++){
		if(f[i]>ans){
			ans=f[i];
		}
		printf("%d ",ans);
	}
	puts("");
	return 0;
}