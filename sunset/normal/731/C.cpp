#include<bits/stdc++.h>

using namespace std;

const int maxn=233333;

int a[maxn];

int f[maxn];

int n,m,k;

int findfa(int x)
{
	return f[x]==x?x:f[x]=findfa(f[x]);
}

void uni(int x,int y)
{
	f[findfa(x)]=findfa(y);
}

vector <int> vis[maxn];

int cnt[maxn];

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		f[i]=i;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		uni(x,y);
	}	
	for(int i=1;i<=n;i++)
		vis[findfa(i)].push_back(a[i]);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int tmp=0;
		for(int j=0;j<vis[i].size();j++)
		{
			cnt[vis[i][j]]++;
			tmp=max(tmp,cnt[vis[i][j]]);
		}
		for(int j=0;j<vis[i].size();j++)
			cnt[vis[i][j]]--;
		ans+=vis[i].size()-tmp;
	}	
	printf("%d",ans);
}