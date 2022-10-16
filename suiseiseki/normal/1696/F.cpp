#include <vector>
#include <cstdio>
const int Maxn=100;
int n;
bool eq_d[Maxn+5][Maxn+5][Maxn+5];
namespace DSU{
	int fa[Maxn+5];
	void init(){
		for(int i=1;i<=n;i++){
			fa[i]=i;
		}
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
}
std::vector<std::vector<int> > lis;
int head[Maxn+5],arrive[Maxn<<1|5],nxt[Maxn<<1|5],tot;
void add_edge(int from,int to){
	arrive[++tot]=to,nxt[tot]=head[from],head[from]=tot;
}
int dis[Maxn+5][Maxn+5];
void clear(){
	for(int i=1;i<=n;i++){
		head[i]=0;
	}
	tot=0;
}
int fa[Maxn+5];
bool work_dfs(int u,int fa,int *dis){
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa){
			continue;
		}
		if(dis[v]!=0){
			return 1;
		}
		dis[v]=dis[u]+1;
		if(work_dfs(v,u,dis)){
			return 1;
		}
	}
	return 0;
}
bool check(std::vector<int> cur){
	for(int i=1;i<(int)cur.size();i++){
		for(int u=1;u<=n;u++){
			if(DSU::find(u)!=cur[i]){
				continue;
			}
			if(i==1){
				fa[u]=1;
			}
			else{
				for(int v=1;v<=n;v++){
					if(DSU::find(v)!=cur[i-1]){
						continue;
					}
					if(eq_d[u][fa[v]][v]){
						fa[u]=v;
						break;
					}
				}
			}
		}
	}
	clear();
	for(int i=2;i<=n;i++){
		add_edge(fa[i],i),add_edge(i,fa[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=0;
		}
		if(work_dfs(i,0,dis[i])){
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if((dis[i][k]==dis[j][k])!=eq_d[i][j][k]){
					return 0;
				}
			}
		}
	}
	return 1;
}
int c_fa[Maxn+5][Maxn+5];
void solve(){
	scanf("%d",&n);
	DSU::init();
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			static char s[Maxn+5];
			scanf("%s",s+1);
			for(int k=1;k<=n;k++){
				eq_d[j][i][k]=eq_d[i][j][k]=s[k]-'0';
			}
			if(eq_d[i][j][1]){
				DSU::merge(i,j);
			}
		}
	}
	lis.clear();
	for(int i=2;i<=n;i++){
		if(DSU::find(i)!=i){
			continue;
		}
		std::vector<int> cur;
		cur.push_back(1);
		cur.push_back(i);
		lis.push_back(cur);
		for(int j=1;j<=n;j++){
			c_fa[i][j]=0;
			if(DSU::find(j)==i){
				c_fa[i][j]=1;
			}
		}
	}
	int all_num=(int)lis.size();
	for(int i=1;i<all_num;i++){
		std::vector<std::vector<int> > nxt_lis;
		for(std::vector<int> cur:lis){
			int son=-1;
			bool flag=1;
			for(int u=1;u<=n;u++){
				if(DSU::find(u)!=cur.back()){
					continue;
				}
				int fa=c_fa[cur[1]][u];
				for(int v=1;v<=n;v++){
					if(v==fa||DSU::find(v)==cur.back()){
						continue;
					}
					if(eq_d[v][fa][u]){
						if(son==-1){
							son=DSU::find(v);
						}
						else if(son!=DSU::find(v)){
							flag=0;
							break;
						}
						c_fa[cur[1]][v]=u;
					}
				}
				if(!flag){
					break;
				}
			}
			if(flag&&son!=-1){
				cur.push_back(son);
				nxt_lis.push_back(cur);
			}
		}
		lis=nxt_lis;
	}
	if(lis.empty()){
		puts("NO");
		return;
	}
	for(std::vector<int> cur:lis){
		if(check(cur)){
			puts("YES");
			for(int i=2;i<=n;i++){
				printf("%d %d\n",fa[i],i);
			}
			return;
		}
	}
	puts("NO");
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}