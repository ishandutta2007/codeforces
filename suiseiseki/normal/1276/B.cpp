#include <queue>
#include <cstdio>
#include <iostream>
using namespace std;
#define Maxn 200000
#define Maxm 500000
int n,m,a,b;
int head[Maxn+5],arrive[Maxm<<1|5],nxt[Maxm<<1|5],tot;
void add_edge(int from,int to){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
}
bool col[Maxn+5][2];
int num[5];
void init(){
	tot=0;
	for(int i=1;i<=n;i++){
		head[i]=0;
		col[i][0]=col[i][1]=0;
	}
	num[0]=num[1]=num[2]=num[3]=num[4]=0;
}
bool vis[Maxn+5];
void clear_vis(){
	for(int i=1;i<=n;i++){
		vis[i]=0;
	}
}
void bfs(int s,int c){
	queue<int> q;
	q.push(s);
	vis[s]=1;
	col[s][c]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=head[u];i;i=nxt[i]){
			int v=arrive[i];
			if(vis[v]){
				continue;
			}
			vis[v]=1;
			col[v][c]=1;
			q.push(v);
		}
	}
}
int main(){
	int t;
	scanf("%d",&t);
	int u,v;
	while(t--){
		scanf("%d%d%d%d",&n,&m,&a,&b);
		init();
		for(int i=1;i<=m;i++){
			scanf("%d%d",&u,&v);
			add_edge(u,v);
			add_edge(v,u);
		}
		clear_vis();
		vis[a]=vis[b]=1;
		bfs(a,0);
		clear_vis();
		vis[a]=vis[b]=1;
		bfs(b,1);
		for(int i=1;i<=n;i++){
			if(i==a||i==b){
				continue;
			}
			if(col[i][0]&&col[i][1]){
				continue;
			}
			if(col[i][0]){
//				printf("Zero %d\n",i);
				num[0]++;
			}
			else{
//				printf("One %d\n",i);
				num[1]++;
			}
		}
		cout<<1ll*num[0]*num[1]<<endl;
	}
	return 0;
}