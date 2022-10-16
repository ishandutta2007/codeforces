#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
using namespace std;
int n,flag,flag2;
int l[100][100],a[100][100100];
int main()
{
	scanf("%d",&n);
	flag=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&l[i][j]);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			a[i][l[i][j]]=1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			flag2=0;
			if(l[i][j]==1)continue;
			for(int k=1;k<=n;k++)
			{
				if(l[i][j]-l[k][j]>0&&a[i][l[i][j]-l[k][j]])
				{
					flag2=1;
					break;
				}
			}
			if(!flag2)flag=0;
		}
	}
	if(flag)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}