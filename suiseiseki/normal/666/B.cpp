#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int INF=0x3f3f3f3f;
struct edge_t{
	int v;
	int next;
}edge[5005];
int head[3005],tot=0;
void add_edge(int u,int v){
	edge[tot].v=v;
	edge[tot].next=head[u];
	head[u]=tot++;
}
struct node{
	int index;
	int len;
	node(){
		index=0;
		len=0;
	}
	node(int _index,int _len){
		index=_index;
		len=_len;
	}
	bool friend operator <(node a,node b){
		if (a.len==b.len){
			return a.index<b.index;
		}
		return a.len<b.len;
	}
};
node longestTo[3005][3],longestFrom[3005][3];
void updateTo(node u,node t) {
	t.len=u.len;
	longestTo[u.index][0]=t;
	sort(longestTo[u.index],longestTo[u.index]+3);
}
void updateFrom(node u,node t){
	longestFrom[u.index][0]=t;
	sort(longestFrom[u.index],longestFrom[u.index]+3);
}
int dis[3005][3005];
bool vis[3005];
void bfs(int st){
	queue<node> q;
	node start(st,0);
	q.push(start);
	vis[st]=1;
	node u;
	while(!q.empty()){
		u=q.front();
		q.pop();
		for (int i=head[u.index];~i;i=edge[i].next){
			node v(edge[i].v,u.len+1);
			if(vis[v.index]){
				continue;
			}
			vis[v.index]=1;
			updateFrom(start,v);
			updateTo(v,start);
			dis[start.index][v.index]=v.len;
			q.push(v);
		}
	}
}
int ans[4];
int main() {
	memset(dis,0x3f,sizeof(dis));
	memset(head,-1,sizeof(head));
	int n,m;
	scanf("%d%d",&n,&m);
	int u,v;
	for(int i=0;i<m;i++) {
		scanf("%d%d",&u,&v);
		add_edge(u,v);
	}
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		bfs(i);
	}
	int sumLen=0;
	for(int b=1;b<=n;b++){
		for(int c=1;c<=n;c++){
			for(int i=2;i>=0;i--){
				for(int j=2;j>=0;j--){
					int a=longestTo[b][i].index;
					int d=longestFrom[c][j].index;
					if(dis[a][b]==INF||dis[b][c]==INF||dis[c][d]==INF){
						continue;
					}
					if(a==b||a==c||a==d||b==c||b==d||c==d){
						continue;
					}
					int t=dis[a][b]+dis[b][c]+dis[c][d];
					if(t>sumLen){
						sumLen=t;
						ans[0]=a;
						ans[1]=b;
						ans[2]=c;
						ans[3]=d;
					}
				}
			}
		}
	}
	for(int i=0;i<4;i++){
		printf("%d ",ans[i]);
	}
	puts("");
	return 0;
}