#include<cstdio>
#include<algorithm>
using namespace std;

const int N=1000+19;
int n,m,A[N][N],Ans;
int F1[N][N],F2[N][N],F3[N][N],F4[N][N];

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) scanf("%d",&A[i][j]);
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++) F1[i][j]=max(F1[i-1][j],F1[i][j-1])+A[i][j];
		for (int j=m;j>=1;j--) F2[i][j]=max(F2[i-1][j],F2[i][j+1])+A[i][j];
	}
	for (int i=n;i>=1;i--)
	{
		for (int j=1;j<=m;j++) F3[i][j]=max(F3[i+1][j],F3[i][j-1])+A[i][j];
		for (int j=m;j>=1;j--) F4[i][j]=max(F4[i+1][j],F4[i][j+1])+A[i][j];
	}
	for (int i=2;i<n;i++)
		for (int j=2;j<m;j++) 
		{
			Ans=max(Ans,F1[i-1][j]+F2[i][j+1]+F3[i][j-1]+F4[i+1][j]);
			Ans=max(Ans,F1[i][j-1]+F2[i-1][j]+F3[i+1][j]+F4[i][j+1]);
		}
	printf("%d\n",Ans);
	return 0;
}