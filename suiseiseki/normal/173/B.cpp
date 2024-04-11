#include <cstdio>
#include <queue>
using namespace std;
char mp[1005][1005];
int head[2005],arrive[2000005],nxt[2000005],tot;
void add_edge(int u,int v){
	arrive[++tot]=v;
	nxt[tot]=head[u];
	head[u]=tot;
}
queue<int> q;
int ans[2005];
bool visit[2005];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",mp[i]+1);
		for(int j=1;j<=m;j++){
			if(mp[i][j]=='#'){
				add_edge(i,n+j);
				add_edge(n+j,i);
			}
		}
	}
	q.push(1);
	visit[1]=1;
	int x;
	while(!q.empty()){
		x=q.front();
		q.pop();
		for(int i=head[x];i;i=nxt[i]){
			if(!visit[arrive[i]]){
				visit[arrive[i]]=1;
				q.push(arrive[i]);
				ans[arrive[i]]=ans[x]+1;
			}
		}
	}
	if(!visit[n]){
		ans[n]=-1;
	}
	printf("%d\n",ans[n]);
	return 0;
}