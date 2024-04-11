/*
ID: Sfiction
OJ: CF
PROB: 512C
*/
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN=200+10;
const int INF=0x7fffffff;

int n;
int num[MAXN];
int c[MAXN][MAXN];
bool vis[MAXN];

int cnt;
int out[MAXN][MAXN];

bool init(){
	int odd=0;
	scanf("%d",&n);
	for (int i=1;i<=n;++i){
		scanf("%d",&num[i]);
		odd+=num[i]&1;
	}
	if (odd*2-n)
		return true;

	for (int i=1;i<=n;++i)
		if (num[i]&1)
			c[0][i]=2;
		else
			c[i][n+1]=2;
	for (int i=1;i<n;++i)
		for (int j=i+1;j<=n;++j){
			int sum=num[i]+num[j];
			int k;
			for (k=2;k*k<=sum && sum%k;++k);
			if (k*k<=sum)
				continue;
			if (num[i]&1)
				c[i][j]=1;
			else
				c[j][i]=1;
		}
	return false;
}

int path(int u,int flow){
	vis[u]=true;
	if (u==n+1)
		return flow;
	for (int t,v=n+1;v>=0;--v)
		if (!vis[v] && c[u][v] && (t=path(v,min(flow,c[u][v])))){
			c[u][v]-=t;
			c[v][u]+=t;
			return t;
		}
	return 0;
}

bool maxflow(){
	int t,ret=0;
	do{
		memset(vis,0,sizeof(vis));
		ret+=t=path(0,INF);
	}while (t);
	return ret<n;
}

void DFS(int u,int a[]){
	vis[u]=true;
	a[++a[0]]=u;
	for (int v=1;v<=n;++v)
		if (!vis[v] && c[u][v]|c[v][u] && c[u][v]==(num[v]&1)){
			DFS(v,a);
			return;
		}
}

int main(){
	if (init() || maxflow())
		puts("Impossible");
	else{
		memset(vis,0,sizeof(vis));
		for (int i=1;i<=n;++i)
			if (!vis[i]){
				DFS(i,out[cnt]);
				++cnt;
			}
		printf("%d",cnt);
		for (int i=0;i<cnt;++i){
			printf("\n%d",out[i][0]);
			for (int j=1;j<=out[i][0];++j)
				printf(" %d",out[i][j]);
		}
	}
	return 0;
}