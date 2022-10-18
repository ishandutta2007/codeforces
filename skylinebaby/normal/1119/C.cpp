#include<bits/stdc++.h>
using namespace std;
int a[600][600];
int b[600][600];
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i = 0;i<n;i++) for(int j = 0;j<m;j++)
	{
		scanf("%d",&a[i][j]);
	}
	for(int i = 0;i<n;i++) for(int j = 0;j<m;j++)
	{
		scanf("%d",&b[i][j]);
	}
	int flag = 0;
	for(int i = 0;i<n;i++)
	{
		int ans = 0;
		for(int j = 0;j<m;j++)
		{
			if(a[i][j]!=b[i][j]) ans++;
		}
		if (ans%2) flag = 1;
	}
	for(int j = 0;j<m;j++)
	{
		int ans = 0;
		for(int i = 0;i<n;i++)
		{
			if(a[i][j]!=b[i][j]) ans++;
		}
		if (ans%2) flag = 1;
	}
	if(flag) printf("No\n");
	else printf("Yes\n");
	return 0;
}