#include<bits/stdc++.h>
using namespace std;
int a[1234];
int b[1234];
vector<int> adj[1234];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 2;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		a[x]++;
		adj[i].push_back(x);
	}
	for(int i = 1;i<=n;i++)
	{
		if (a[i]==0)
		{
			for(int j =0;j<adj[i].size();j++)
			{
				int y = adj[i][j];
				b[y]++;
			}
		}
	}
	for(int i = 1;i<=n;i++)
	{
		if (a[i]!=0&&b[i]<3) 
		{
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	return 0;
}