/*
ID: Sfiction
OJ: CF
PROB: 500D
*/
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int MAXN=300100;

int edge[MAXN][3];

int n;
vector<int> E[MAXN];
int size[MAXN];
bool vis[MAXN];

double ans,sum;

void DFS(int u){
	vis[u]=true;
	size[u]=1;
	for (int v,i=E[u].size()-1;i>=0;--i)
		if (!vis[v=E[u][i]]){
			DFS(v);
			size[u]+=size[v];
		}
}

void change(int i,int c){
	double u=size[edge[i][0]];
	double v=size[edge[i][1]];
	if (v>u)
		v=u;
	u=n-v;
	if (u>1)
		ans+=c*u*(u-1)*v;
	if (v>1)
		ans+=c*v*(v-1)*u;
}

int main(){
	scanf("%d",&n);
	for (int i=1;i<n;++i){
		scanf("%d%d%d",&edge[i][0],&edge[i][1],&edge[i][2]);
		E[edge[i][0]].push_back(edge[i][1]);
		E[edge[i][1]].push_back(edge[i][0]);
	}
	memset(vis,0,sizeof(vis));
	memset(size,0,sizeof(size));
	DFS(1);
	sum=n*double(n-1)*(n-2)/6.0;

	for (int i=1;i<n;++i)
		change(i,edge[i][2]);
	int m,id,c;
	scanf("%d",&m);
	while (m--){
		scanf("%d%d",&id,&c);
		change(id,c-edge[id][2]);
		edge[id][2]=c;
		printf("%.12lf\n",ans/sum);
	}
	return 0;
}