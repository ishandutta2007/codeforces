#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>

using namespace std;
int n,m;
int a[2333],c1[2333],c2[2333];
int c[3][2333][2333],rc[3][2333][2333];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),c1[i]=c1[i-1]+(a[i]==1);
	for(int i=n;i>=1;i--)c2[i]=c2[i+1]+(a[i]==2);
	/*for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(a[j]==1)
				c[1][i][j]=c[1][i][j-1]+1,
				c[2][i][j]=max(c[2][i][j-1],c[1][i][j]);
			else
				c[1][i][j]=c[1][i][j-1]+1,
				c[2][i][j]=max(c[2][i][j-1]+1,c[1][i][j-1]+1);
		}
	}*/
	for(int i=n;i>=1;i--)
	{
		for(int j=i;j>=1;j--)
		{
			if(a[j]==1)
				rc[1][i][j]=rc[1][i][j+1]+1,
				rc[2][i][j]=max(rc[2][i][j+1],rc[1][i][j]);
			else
				rc[1][i][j]=rc[1][i][j+1],
				rc[2][i][j]=max(rc[2][i][j+1],rc[1][i][j+1])+1;
			//cout<<i<<' '<<j<<' '<<rc[1][i][j]<<' '<<rc[2][i][j]<<endl;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			ans=max(ans,c1[i-1]+c2[j+1]+rc[2][j][i]);
			//cout<<i<<' '<<j<<' '<<c1[i-1]+c2[j+1]+rc[2][j][i]<<endl;
		}
	}
	printf("%d\n",ans);
	return 0;
}