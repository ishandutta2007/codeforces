#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<vector>
using namespace std;
int n,m;
int a[111][111],t[111][111];
int r[111],c[111];
vector<int> tmp,ans;
inline void check(int x)
{
	tmp.clear();
	for(int i=1;i<=100;i++)r[i]=c[i]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			t[i][j]=a[i][j];
		}
	}
	for(int i=1;i<=x;i++)
	{
		tmp.push_back(-1);
		r[1]++;
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=x+1;j<=a[1][i];j++)
		{
			tmp.push_back(i);
			c[i]++;
		}
	}
	for(int i=2;i<=n;i++)
	{
		for(int j=c[1]+1;j<=a[i][1];j++)
		{
			tmp.push_back(-i);
			r[i]++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]!=r[i]+c[j])return;
		}
	}
	if(ans.size()==0||ans.size()>tmp.size())ans=tmp;
}
char str[2][5]={"row","col"};
int main()
{
	scanf("%d%d",&n,&m);
	bool fl=true;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&a[i][j]);
			if(a[i][j]!=0)fl=false;
		}
	}
	if(fl)
	{
		return printf("0\n"),0;
	}
	int minn=233333333;
	for(int i=1;i<=m;i++)minn=min(minn,a[1][i]);
	for(int i=0;i<=minn;i++)
	{
		check(i);
	}
	if(!ans.size())printf("-1\n");
	else
	{
		printf("%d\n",int(ans.size()));
		for(auto x:ans)printf("%s %d\n",str[x>0],x>0?x:-x);
	}
	return 0;
}