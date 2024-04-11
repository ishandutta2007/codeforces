#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int Maxn=100+19;
int A[Maxn][Maxn],tmp[27];
int n,m;

inline int getMin(int x,int y)
{
	if (A[x][y]) return A[x][y];
	for (int i='A';;i++)
		if (A[x][y-1]!=i&&A[x][y+1]!=i&&A[x-1][y]!=i&&A[x+1][y]!=i) return i;
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			int k=0,t;
			putchar(t=getMin(i,j));
			if (A[i][j]) continue;
			while (i+k<=n&&j+k<=m&&getMin(i,j+k)==t) k++;
			for (int l=i;l<i+k;l++)
				for (int m=j;m<j+k;m++) A[l][m]=t;
		}
		puts("");
	}
}