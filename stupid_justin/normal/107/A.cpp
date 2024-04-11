#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
const int N=1005;
vector<int> vec1[N];
vector<int> vec2[N];
void add(int u,int v)
{
	vec1[u].push_back(v);
	vec2[v].push_back(u);
}
int len[N][N];
void dfs(int x,int y,int dis)
{
	if (vec1[y].size()==1) dfs(x,vec1[y][0],min(dis,len[y][vec1[y][0]]));
	else printf("%d %d %d\n",x,y,dis);
}

int n,m,cnt;
int main()
{
	cin>>n>>m;
	while (m--)
	{
		int x,y,z;
		cin>>x>>y>>z;
		len[x][y]=z;
		add(x,y);
	}
	for (int i=1;i<=n;i++)
	{
		if (vec1[i].size()==1 && vec2[i].size()==0) cnt++;
	}
	cout<<cnt<<endl;
	for (int i=1;i<=n;i++)
	{
		if (vec1[i].size()==1 && vec2[i].size()==0) dfs(i,i,inf);
	}
}