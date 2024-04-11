#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>

using namespace std;
const int MAXN=300010;
int n,m;
int a[MAXN],vis[MAXN];
int main()
{
	scanf("%d",&n);
	int r=n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("1 ");
	for(int i=1;i<=n;i++)
	{
		vis[a[i]]=1;
		while(vis[r]==1)r--;
		//for(int j=1;j<=n;j++)cout<<vis[j]<<' ';
		//cout<<endl<<r<<endl;
		printf("%d ",i-(n-r)+1);
	}
	return 0;
}