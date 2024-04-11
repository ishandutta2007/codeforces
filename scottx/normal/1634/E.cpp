#include<bits/stdc++.h>
using namespace std;
const int N=400005;
int n,c,g;
vector<int>a[N],vis[N],z,b[N];
struct ed{int v,p,q;};
vector<ed>e[N];
void dfs(int u)
{
	while(e[u].size())
	{
		int v=e[u].back().v,p=e[u].back().p,q=e[u].back().q;
		e[u].pop_back();
		if(vis[p][q])
			continue;
		vis[p][q]=1;
		dfs(v);
		g^=1;
		b[p][q]=g;
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int k;
		scanf("%d",&k);
		a[i].resize(k);
		b[i].resize(k);
		vis[i].resize(k);
		for(int j=0;j<k;j++)
		{
			scanf("%d",&a[i][j]);
			z.push_back(a[i][j]);
		}
	}
	sort(z.begin(),z.end());
	z.erase(unique(z.begin(),z.end()),z.end());
	c=n+z.size();
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<a[i].size();j++)
		{
			a[i][j]=lower_bound(z.begin(),z.end(),a[i][j])-z.begin()+n+1;
			e[a[i][j]].push_back({i,i,j});
			e[i].push_back({a[i][j],i,j});	
		}
	}
	for(int i=1;i<=c;i++)
	{
		if(e[i].size()&1)
		{
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	for(int i=1;i<=c;i++)
		dfs(i);
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<b[i].size();j++)
			printf("%c",(b[i][j]?'L':'R'));
		puts("");
	}
	return 0;
}