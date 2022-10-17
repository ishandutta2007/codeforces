#include <cstdio>
#include <string>
#include <queue>
using namespace std;
const int maxn=20;
char g[maxn][maxn];
int ax,ay,sx,sy;
int N,M,len;
bool vis[20000005];
int dx[]= {0,0,1,-1};
int dy[]= {1,-1,0,0};
struct node {
	int x[10],y[10];
	int step;
	node() {
		step=0;
	}
};
int find(node a,int i) {
	for(int j=0; j<4; j++) {
		int x=a.x[i-1]+dx[j];
		int y=a.y[i-1]+dy[j];
		if(x==a.x[i]&&y==a.y[i])return j;
	}
}
int gethash(int sx,int sy,node a) {
	int hash=sx*M+sy;
	for(int i=1; i<len; i++)
		hash=(hash<<2)+find(a,i);
	return hash;
}
void solve(node s) {
	queue<node> q;
	s.step=0;
	q.push(s);
	while(!q.empty()) {
		node a=q.front();
		q.pop();
		for(int i=0; i<4; i++) {
			int x=a.x[0]+dx[i];
			int y=a.y[0]+dy[i];
			if(x<1||x>N||y<1||y>M||g[x][y]=='#')continue;
			bool flag=1;
			for(int j=1; j<len-1; j++)
				if(x==a.x[j]&&y==a.y[j]) {
					flag=0;
					break;
				}
			if(!flag)continue;
			node tmp;
			tmp.x[0]=x,tmp.y[0]=y;
			for(int j=1; j<len; j++) {
				tmp.x[j]=a.x[j-1];
				tmp.y[j]=a.y[j-1];
			}
			int hash=gethash(x,y,tmp);
			if(!vis[hash]) {
				tmp.step=a.step+1;
				vis[hash]=1;
				q.push(tmp);
			}
			if(x==ax&&y==ay) {
				printf("%d\n",tmp.step);
				return;
			}
		}
	}
	printf("-1\n");
}
int main() {
	scanf("%d%d",&N,&M);
	node s;
	for(int i=1; i<=N; i++) {
		scanf("%s",g[i]+1);
		for(int j=1; j<=M; j++) {
			if(g[i][j]=='@')ax=i,ay=j;
			else if(g[i][j]>='1'&&g[i][j]<='9') {
				if(g[i][j]=='1')sx=i,sy=j;
				s.x[g[i][j]-'1']=i;
				s.y[g[i][j]-'1']=j;
				len++;
				g[i][j]='.';
			}
		}
	}
	int tmp=gethash(sx,sy,s);
	vis[tmp]=1;
	solve(s);
	return 0;
}