#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int t;
int n,m,k;
int a[35][35][55];
void dp()
{
	memset(a,0x3f,sizeof(a));
	for(int i=0;i<=30;i++)
	{
		for(int j=0;j<=30;j++)
		{
			a[i][j][0]=0;
			if(i*j<=50)a[i][j][i*j]=0;
		}
	}
	for(int i=1;i<=30;i++)
	{
		for(int j=1;j<=30;j++)
		{
			int p=min(i*j,50);
			for(int k=1;k<=p;k++)
			{
				for(int x=1;x<=i/2;x++)
				{
					int z1=min(x*j,k);
					for(int ch=0;ch<=z1;ch++)
						a[i][j][k]=min(a[i][j][k],a[x][j][ch]+a[i-x][j][k-ch]+j*j); 
				}
				for(int y=1;y<=j/2;y++)
				{
					int z2=min(y*i,k);
					for(int ch=0;ch<=z2;ch++)
						a[i][j][k]=min(a[i][j][k],a[i][y][ch]+a[i][j-y][k-ch]+i*i);
				}
			}
		}
	}
}
int main()
{
	dp();
	cin>>t;
	while(t--)
	{
		cin>>n>>m>>k;
		cout<<a[n][m][k]<<endl;
	}
    return 0;
}