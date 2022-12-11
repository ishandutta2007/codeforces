#include<cstdio>
using namespace std;

const int Maxn=100+19;
int n,A[Maxn][32],B[Maxn][Maxn],x;

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) 
		for (int j=1;j<=n;j++) 
		{
			scanf("%d",&x);
			if (x!=-1)
				for (int k=0;k<=30;k++)
				{
					if (x&1)
						A[i][k]=A[j][k]=1;
					x>>=1;
				}
			B[i][j]=x;
		}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (B[i][j]==-1) 
				for (int k=0;k<=30;k++) A[i][k]=A[j][k]=A[i][k]|A[j][k];
	for (int i=1;i<=n;i++)
	{
		int x=0;
		for (int k=30;k>=0;k--) x=x*2+A[i][k];
		printf("%d ",x);
	}
}