#include <queue>
#include <cstdio>
#include <vector>
const int Maxn=(1<<16);
int n;
std::vector<int> g[Maxn+5];
bool vis[Maxn+5],in_q[Maxn+5];
int p[Maxn+5],q[Maxn+5],col[Maxn+5];
std::queue<int> qu;
int find_num(int n){
	if(n==0){
		return 0;
	}
	return find_num(n-(n&(-n)))+1;
}
void solve(){
	scanf("%d",&n);
	for(int i=0;i<(1<<n);i++){
		g[i].clear();
		vis[i]=in_q[i]=0;
		p[i]=col[i]=0;
	}
	int d_cnt=0;
	for(int i=1;i<=n*(1<<(n-1));i++){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v),g[v].push_back(u);
		if(u>v){
			std::swap(u,v);
		}
		if(u==0){
			p[v]=(1<<d_cnt);
			d_cnt++;
			qu.push(v);
		}
	}
	p[0]=0;
	vis[0]=1;
	while(!qu.empty()){
		int u=qu.front();
		qu.pop();
		vis[u]=1;
		for(int i=0;i<(int)g[u].size();i++){
			int v=g[u][i];
			if(!vis[v]){
				p[v]|=p[u];
				if(!in_q[v]){
					in_q[v]=1;
					qu.push(v);
				}
			}
		}
	}
	col[0]=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<(1<<i);j++){
			col[j+(1<<i)]=col[j]^i;
		}
	}
	for(int i=0;i<(1<<n);i++){
		q[p[i]]=i;
	}
	for(int i=0;i<(1<<n);i++){
		printf("%d ",q[i]);
	}
	puts("");
	if(find_num(n)==1){
		for(int i=0;i<(1<<n);i++){
			printf("%d ",col[p[i]]);
		}
		puts("");
	}
	else{
		puts("-1");
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