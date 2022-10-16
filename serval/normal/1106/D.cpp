#include <cstdio>
#include <queue>
using namespace std;
const int N=100005;
const int M=500005;
int n,m;
int u,v;
int h[N],to[M],nx[M],cnt;
priority_queue <int,vector<int>,greater<int> > q;
bool vis[N],inq[N];
void addedge(int u,int v)
{
	cnt++;
	to[cnt]=v;
	nx[cnt]=h[u];
	h[u]=cnt;
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		addedge(u,v);
		addedge(v,u);
	}
	q.push(1);
	inq[1]=1;
	while (!q.empty())
	{
		int cur=q.top();
		q.pop();
		printf("%d ",cur);
		vis[cur]=1;
		for (int i=h[cur];i;i=nx[i])
			if (!vis[to[i]]&&!inq[to[i]])
			{
				inq[to[i]]=1;
				q.push(to[i]);
			}
	}
	printf("\n");
	return 0;
}