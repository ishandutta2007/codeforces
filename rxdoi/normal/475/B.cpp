#include<cstdio>
#include<vector>
#include<string>
#include<iostream>
using namespace std;

const int Maxn=20+19;
int A[Maxn][Maxn][Maxn][Maxn];
int n,m;
string a,b;

int main()
{
	scanf("%d%d",&n,&m);
	cin>>a>>b;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		{
			if (a[i-1]=='>')
				for (int k=j;k<=m;k++) A[i][j][i][k]=1;
			else
				for (int k=1;k<=j;k++) A[i][j][i][k]=1;
			if (b[j-1]=='^')
				for (int k=1;k<=i;k++) A[i][j][k][j]=1;
			else 
				for (int k=i;k<=n;k++) A[i][j][k][j]=1;
		}
	for (int k=1;k<=n;k++)
		for (int l=1;l<=m;l++)
			for (int i=1;i<=n;i++)
				for (int j=1;j<=m;j++)
					for (int x=1;x<=n;x++)
						for (int y=1;y<=m;y++)
							A[i][j][x][y]|=A[i][j][k][l]&&A[k][l][x][y];
	int Flag=1;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			for (int k=1;k<=n;k++)
				for (int l=1;l<=m;l++)
					if (!A[i][j][k][l]) Flag=0;
	Flag?puts("YES"):puts("NO");
}