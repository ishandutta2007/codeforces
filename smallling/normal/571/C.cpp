#include<cstdio>
#include<vector>
#include<algorithm> 

using namespace std;

int n,m,k,x,flag[200020],bo[200020],rely[200020],color[200020];
vector<pair<int,int> >a[200020],f[200020];

int dfs(int x)
{
	flag[x]=1;
	for(int i=0;i<f[x].size();i++)
	{
		int nowv=f[x][i].first,nowx=f[x][i].second;
		if(bo[nowx])continue;
		bo[nowx]=1;
		if(flag[nowv])
		{
			rely[x]=nowx;
			return 1;
		}
		if(dfs(nowv))
		{
			rely[x]=nowx;
			return 1;
		}
		rely[nowv]=nowx;
	}
	return 0;
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&k);
		for(int j=1;j<=k;j++)
		{
			scanf("%d",&x);
			if(x<0)a[-x].push_back(make_pair(i,0));
			else a[x].push_back(make_pair(i,1));
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(a[i].size()==0)continue;
		if(a[i].size()==1)
		{
			color[i]=a[i][0].second;
			flag[a[i][0].first]=1;
		}
		else
		{
			if(a[i][0].second==a[i][1].second)
			{
				flag[a[i][0].first]=flag[a[i][1].first]=1;
				color[i]=a[i][0].second;
			}
			else
			{
				f[a[i][0].first].push_back(make_pair(a[i][1].first,i));
				f[a[i][1].first].push_back(make_pair(a[i][0].first,i));
			}
		}
	}
	for(int i=1;i<=n;i++)
		if(!flag[i])
			if(!dfs(i))return puts("NO"),0;
	puts("YES");
	for(int i=1;i<=n;i++)
		if(rely[i])
		{
			for(int j=0;j<a[rely[i]].size();j++)
				if(a[rely[i]][j].first==i)color[rely[i]]=a[rely[i]][j].second;
		}
	for(int i=1;i<=m;i++)putchar(color[i]+'0');
}