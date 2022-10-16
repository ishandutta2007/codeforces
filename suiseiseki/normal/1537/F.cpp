#include <cstdio>
#include <cstring>
const int Maxn=200000;
typedef long long ll;
int a[Maxn+5],b[Maxn+5];
int n,m;
ll sum[Maxn+5];
int fa[Maxn+5];
struct Edge{
	int u,v;
}edge[Maxn+5];
int find(int x){
	if(fa[x]==x){
		return x;
	}
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	int fa_x=find(x),fa_y=find(y);
	if(fa_x==fa_y){
		return;
	}
	sum[fa_x]+=sum[fa_y];
	fa[fa_y]=fa_x;
}
int head[Maxn+5],arrive[Maxn<<1|5],nxt[Maxn<<1|5],tot;
void add_edge(int from,int to){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
}
int col[Maxn+5];
ll col_sum[5];
ll all_sum;
bool dfs(int u,int c){
	if(col[u]!=-1){
		if(c==col[u]){
			return 1;
		}
		return 0;
	}
	all_sum+=sum[u];
	col_sum[c]+=sum[u];
	col[u]=c;
	bool flag=1;
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(!dfs(v,c^1)){
			flag=0;
		}
	}
	return flag;
}
int main(){
	int T;
	scanf("%d",&T);
	int u,v;
	int len;
	bool flag;
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		for(int i=1;i<=n;i++){
			scanf("%d",&b[i]);
			a[i]-=b[i];
			sum[i]=a[i];
			fa[i]=i;
		}
		len=0;
		for(int i=1;i<=m;i++){
			scanf("%d%d",&u,&v);
			edge[++len].u=u;
			edge[len].v=v;
		}
		tot=0;
		memset(head,0,sizeof head);
		for(int i=1;i<=len;i++){
			add_edge(find(edge[i].u),find(edge[i].v));
			add_edge(find(edge[i].v),find(edge[i].u));
		}
		flag=1;
		all_sum=0;
		memset(col,-1,sizeof col);
		for(int i=1;i<=n;i++){
			if(find(i)==i&&col[i]==-1){
				col_sum[0]=col_sum[1]=0;
				if(dfs(i,0)){
					if(col_sum[0]!=col_sum[1]){
						flag=0;
						break;
					}
				}
				else{
					if(all_sum&1){
						flag=0;
						break;
					}
				}
			}
		}
		if(flag){
			puts("YES");
		}
		else{
			puts("NO");
		}
	}
	return 0;
}