#include <queue>
#include <cstdio>
using namespace std;
typedef long long ll;
const int Maxn=300000;
int n,m;
int to[Maxn+5],fa[Maxn+5];
int in[Maxn+5];
int head[Maxn+5],arrive[Maxn+5],nxt[Maxn+5],tot;
int p[Maxn+5];
bool vis[Maxn+5];
void add_edge(int from,int to){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
}
int find(int x){
	if(x==fa[x]){
		return x;
	}
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	int fa_x=find(x),fa_y=find(y);
	if(fa_x==fa_y){
		return;
	}
	fa[fa_y]=fa_x;
}
queue<int> q;
int ans[Maxn+5],ans_len;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&p[i]);
		add_edge(p[i],i);
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		if(to[u]||fa[v]!=v||find(u)==v){
			puts("0");
			return 0;
		}
		merge(u,v);
		to[u]=v;
	}
	for(int i=1;i<=n;i++){
		if(find(i)==i){
			for(int j=i;j;j=to[j]){
				vis[j]=1;
				if(p[j]&&find(p[j])!=i){
					in[i]++;
				}
				else if(p[j]&&!vis[p[j]]){
					puts("0");
					return 0;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(find(i)==i&&in[i]==0){
			q.push(i);
		}
	}
	while(!q.empty()){
		int tmp_u=q.front();
		q.pop();
		for(int u=tmp_u;u;u=to[u]){
			ans[++ans_len]=u;
			for(int i=head[u];i;i=nxt[i]){
				int v=find(arrive[i]);
				in[v]--;
				if(in[v]==0){
					q.push(v);
				}
			}
		}
	}
	if(ans_len!=n){
		puts("0");
		return 0;
	}
	for(int i=1;i<=n;i++){
		printf("%d ",ans[i]);
	}
	puts("");
	return 0;
}