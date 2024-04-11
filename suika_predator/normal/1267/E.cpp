#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105][105];
vector<pair<int,int> >v[105];
vector<int>ans[105];
bool cmp(pair<int,int>p,pair<int,int>q)
{
	return p.first>q.first;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
		}
		for(int j=1;j<n;j++)
		{
			v[j].push_back(make_pair(a[i][j]-a[i][n],i));
		}
	}
	for(int i=1;i<n;i++)
	{
		sort(v[i].begin(),v[i].end(),cmp);
		int tmp=0,j;
		for(j=0;j<m;j++)
		{
			if(tmp+v[i][j].first<0)break;
			tmp+=v[i][j].first;
		}
		for(;j<m;j++){ans[i].push_back(v[i][j].second);/*cerr<<i<<" "<<v[i][j].second<<endl;*/}
	}
	int anss=100000,k=-1;
	for(int i=1;i<n;i++)
	{
		if(ans[i].size()<anss)anss=ans[i].size(),k=i;
	}
	printf("%d\n",anss);
	for(int i=0;i<anss;i++)printf("%d ",ans[k][i]);
	printf("\n");
	
	return 0;
}