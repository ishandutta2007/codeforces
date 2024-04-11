#include <queue>
#include <vector>
#include <cstdio>
using namespace std;
const int d[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
const int Maxp=20;
const int Maxn=Maxp*Maxp;
const int Maxm=4*Maxn;
int n,m;
char s[Maxp+5][Maxp+5];
int id[Maxp+5][Maxp+5],id_tot;
char ans[Maxp<<1|5][Maxp<<1|5];
int x[Maxm+5],y[Maxm+5];
bool col[Maxn+5];
int u[Maxm+5],v[Maxm+5];
bool vis[Maxm+5];
int lim[Maxn+5];
int edge_tot;
int pre[Maxm+5];
vector<int> lis[2][Maxn+5];
vector<int> g[Maxm+5];
void add_edge(int from,int to){
	g[from].push_back(to);
}
int fa[Maxn+5],sz[Maxn+5];
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
	sz[fa_x]+=sz[fa_y];
}
bool check(int x,int y){
	int fa_x=find(x),fa_y=find(y);
	if(fa_x==fa_y){
		return 0;
	}
	return (sz[fa_x]+sz[fa_y]==id_tot);
}
bool augument(){
	for(int i=0;i<=edge_tot+1;i++){
		pre[i]=-1;
		g[i].clear();
	}
	for(int i=1;i<=id_tot;i++){
		if(col[i]){
			lis[0][i].clear();
			lis[1][i].clear();
		}
	}
	for(int i=1;i<=edge_tot;i++){
		if(col[u[i]]){
			lis[vis[i]][u[i]].push_back(i);
		}
		else if(col[v[i]]){
			lis[vis[i]][v[i]].push_back(i);
		}
		else{
			add_edge(i,edge_tot+1);
		}
	}
	for(int i=1;i<=id_tot;i++){
		if(col[i]){
			if((int)lis[1][i].size()<lim[i]){
				for(int j=0;j<(int)lis[0][i].size();j++){
					add_edge(lis[0][i][j],edge_tot+1);
				}
			}
			else{
				for(int j=0;j<(int)lis[0][i].size();j++){
					for(int k=0;k<(int)lis[1][i].size();k++){
						add_edge(lis[0][i][j],lis[1][i][k]);
					}
				}
			}
		}
	}
	for(int i=1;i<=edge_tot;i++){
		if(!vis[i]){
			for(int j=1;j<=id_tot;j++){
				fa[j]=j;
				sz[j]=1;
			}
			for(int j=1;j<=edge_tot;j++){
				if(!vis[j]&&j!=i){
					merge(u[j],v[j]);
				}
			}
			if(sz[find(1)]==id_tot){
				add_edge(0,i);
				if(!g[i].empty()&&g[i][0]==edge_tot+1){
					vis[i]=1;
					return 1;
				}
			}
			else{
				for(int j=1;j<=edge_tot;j++){
					if(vis[j]&&check(u[j],v[j])){
						add_edge(j,i);
					}
				}
			}
		}
	}
	queue<int> q;
	q.push(0);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=0;i<(int)g[u].size();i++){
			int v=g[u][i];
			if(pre[v]==-1){
				pre[v]=u;
				q.push(v);
				if(v==edge_tot+1){
					break;
				}
			}
		}
		if(pre[edge_tot+1]!=-1){
			break;
		}
	}
	if(pre[edge_tot+1]==-1){
		return 0;
	}
	int u=pre[edge_tot+1];
	while(u){
		vis[u]^=1;
		u=pre[u];
	}
	return 1;
}
void solve(){
	id_tot=edge_tot=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",s[i]+1);
		for(int j=1;j<=m;j++){
			if(s[i][j]=='O'){
				id[i][j]=++id_tot;
				if((!((i+j)&1))&&(i!=1||j!=1)){
					col[id[i][j]]=1;
				}
				else{
					col[id[i][j]]=0;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i][j]=='O'){
				if(i<n&&s[i+1][j]=='O'){
					edge_tot++;
					u[edge_tot]=id[i][j];
					v[edge_tot]=id[i+1][j];
					x[edge_tot]=(i<<1);
					y[edge_tot]=(j<<1)-1;
					vis[edge_tot]=0;
				}
				if(j<m&&s[i][j+1]=='O'){
					edge_tot++;
					u[edge_tot]=id[i][j];
					v[edge_tot]=id[i][j+1];
					x[edge_tot]=(i<<1)-1;
					y[edge_tot]=(j<<1);
					vis[edge_tot]=0;
				}
				if(col[id[i][j]]){
					lim[id[i][j]]=0;
					for(int k=0;k<4;k++){
						int nx=i+d[k][0],ny=j+d[k][1];
						if(nx<1||ny<1||nx>n||ny>m||s[nx][ny]=='X'){
							continue;
						}
						lim[id[i][j]]++;
					}
					lim[id[i][j]]-=2;
					if(lim[id[i][j]]<0){
						puts("NO");
						return;
					}
				}
			}
		}
	}
	int sum=0;
	while(augument()){
		sum++;
	}
	if(edge_tot-sum!=id_tot-1){
		puts("NO");
		return;
	}
	for(int i=1;i<(n<<1);i++){
		for(int j=1;j<(m<<1);j++){
			ans[i][j]=' ';
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			ans[(i<<1)-1][(j<<1)-1]=s[i][j];
		}
	}
	for(int i=1;i<=edge_tot;i++){
		if(!vis[i]){
			ans[x[i]][y[i]]='O';
		}
	}
	puts("YES");
	for(int i=1;i<(n<<1);i++){
		for(int j=1;j<(m<<1);j++){
			putchar(ans[i][j]);
		}
		puts("");
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}