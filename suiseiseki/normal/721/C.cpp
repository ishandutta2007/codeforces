#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
#define maxn 5000
struct Node {
	int point,cost;
} ans[maxn+5];
int dp[maxn+5][maxn+5];
vector<Node> ts[maxn+5];
queue<Node> q;
int pre[maxn+5][maxn+5],n,t;
bool used[maxn+5][maxn+5];
void BFS() {
	for(int i=0; i<=n; i++) {
		for(int j=0; j<=n; j++) {
			dp[i][j]=t+1;
			pre[i][j]=0;     
		}
	}
	Node start,now;
	start.point=1;
	start.cost=1;
	q.push(start);
	used[1][1]=1;
	dp[1][1]=0;
	int u,v,x,y;
	while(!q.empty()) {
		now=q.front();
		q.pop();
		u=now.point,v=now.cost;
		used[u][v]=0;
		for(unsigned i=0; i<ts[u].size(); i++) {
			x=ts[u][i].point;
			y=ts[u][i].cost;
			if(dp[u][v]+y>t) {
				continue;
			}
			if(dp[x][v+1]>dp[u][v]+y) {
				dp[x][v+1]=dp[u][v]+y;
				pre[x][v+1]=u;
				if(used[x][v+1]) {
					continue;
				}
				used[x][v+1]=1;
				Node nexts;
				nexts.point=x;
				nexts.cost=v+1;
				q.push(nexts);
			}
		}
	}
}
void print(int x,int y) {
	if(pre[x][y]!=0) {
		print(pre[x][y],y-1);
	}
	if(x==n) {
		printf("%d\n",x);
	} else {
		printf("%d ",x);
	}
}
int main() {
	int x,y,z,m;
	scanf("%d%d%d",&n,&m,&t);
	Node now;
	for(int i=1; i<=m; i++) {
		scanf("%d%d%d",&x,&y,&z);
		now.point=y;
		now.cost=z;
		ts[x].push_back(now);
	}
	BFS();
	int ans=0;
	for(int i=1; i<=n; i++) {
		if(dp[n][i]<=t) {
			ans=i;
		}
	}
	printf("%d\n",ans);
	print(n,ans);
	return 0;
}