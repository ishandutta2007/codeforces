#include<bits/stdc++.h>
#define F first
#define S second
#define MAXV 200005
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
vector<int> G[MAXV];
bool used[MAXV],visited[MAXV];
int suf[MAXV],pre[MAXV];
int num,ans[MAXV];
queue<int> que;
void del(int x)
{
	pre[suf[x]]=pre[x];
	suf[pre[x]]=suf[x];
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<=n;i++)
	{
		suf[i]=i+1;
		pre[i+1]=i;
	}
	for(int i=0;i<m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	memset(used,false,sizeof(used));
	memset(visited,false,sizeof(visited));
	num=0;
	for(int i=1;i<=n;i++)
	{
		if(visited[i]) continue;
		ans[num++]=1;
		visited[i]=true;
		que.push(i);
		del(i);
		while(que.size())
		{
			int v=que.front();que.pop();
			for(int j=0;j<G[v].size();j++)
			{
				int to=G[v][j];
				if(visited[to]) continue;
				used[to]=true;
			}
			for(int j=suf[0];j<=n;j=suf[j])
			{
				if(!used[j])
				{
					visited[j]=true;
					ans[num-1]++;
					del(j);
					que.push(j);
				}
				else used[j]=false;
			}

		}
	}
	sort(ans,ans+num);
	printf("%d\n",num);
	for(int i=0;i<num;i++)
		printf("%d ",ans[i]);
	printf("\n");
	return 0;
}