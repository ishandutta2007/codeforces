#include<cstdio>
#include<algorithm>
using namespace std;

const int Maxn=400+19;
typedef int Mt[Maxn][Maxn];
char s[Maxn];
int n,m,Ans;
Mt A,R,C,Lx,Rx;

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		scanf("%s",s);
		for (int j=1;j<=m;j++) A[i][j]=s[j-1]-'0';
	}
	for (int i=1;i<=n;i++) 
		for (int j=1;j<=m;j++) 
		{
			R[i][j]=R[i][j-1]+A[i][j];
			C[i][j]=C[i-1][j]+A[i][j];
			Lx[i][j]=Lx[i-1][j+1]+A[i][j];
			Rx[i][j]=Rx[i-1][j-1]+A[i][j];
		}
	for (int x=1;x<=n;x++)
		for (int y=1;y<=m;y++)
			if (!A[x][y])
			{
				
				//n
				for (int k=2;x+k-1<=n&&y+k-1<=m;k++) 
				{
					if (C[x+k-1][y]!=C[x-1][y]) break;
					if (R[x][y+k-1]!=R[x][y-1]) break;
					Ans+=(Lx[x+k-1][y]==Lx[x-1][y+k-1+1]);
				}
				for (int k=2;x+k-1<=n&&y-k+1>=1;k++)
				{
					if (C[x+k-1][y]!=C[x-1][y]) break;
					if (R[x][y-k+1-1]!=R[x][y]) break;
					Ans+=(Rx[x+k-1][y]==Rx[x-1][y-k+1-1]);
				}
				for (int k=2;x-k+1>=1&&y+k-1<=m;k++) 
				{
					if (C[x-k+1-1][y]!=C[x][y]) break;
					if (R[x][y+k-1]!=R[x][y-1]) break;
					Ans+=(Rx[x-k+1-1][y-1]==Rx[x][y+k-1]);
				}
				for (int k=2;x-k+1>=1&&y-k+1>=1;k++)
				{
					if (C[x-k+1-1][y]!=C[x][y]) break;
					if (R[x][y-k+1-1]!=R[x][y]) break;
					Ans+=(Lx[x-k+1-1][y+1]==Lx[x][y-k+1]);
				}
				
				//sqrt(2)n 
				
				for (int k=2;x+k-1<=n&&y+k-1<=m&&y-k+1>=1;k++)
				{
					if (R[x][y+k-1]!=R[x][y-k+1-1]) break;
					if (Lx[x+k-1][y]==Lx[x-1][y+k-1+1]
						&&Rx[x+k-1][y]==Rx[x-1][y-k+1-1]) Ans++;
				}
				for (int k=2;x-k+1>=1&&y+k-1<=m&&y-k+1>=1;k++)
				{
					if (R[x][y+k-1]!=R[x][y-k+1-1]) break;
					if (Lx[x-k+1-1][y+1]==Lx[x][y-k+1]
						&&Rx[x-k+1-1][y-1]==Rx[x][y+k-1]) Ans++;
				}
				for (int k=2;y-k+1>=1&&x-k+1>=1&&x+k-1<=n;k++)
				{
					if (C[x+k-1][y]!=C[x-k+1-1][y]) break;
					if (Lx[x-k+1-1][y+1]==Lx[x][y-k+1]
						&&Rx[x-1][y-k+1-1]==Rx[x+k-1][y]) Ans++;
				}
				for (int k=2;y+k-1<=m&&x-k+1>=1&&x+k-1<=n;k++)
				{
					if (C[x+k-1][y]!=C[x-k+1-1][y]) break;
					if (Lx[x-1][y+k-1+1]==Lx[x+k-1][y]
						&&Rx[x-k+1-1][y-1]==Rx[x][y+k-1]) Ans++;
				}
				
			}
	printf("%d\n",Ans);
}