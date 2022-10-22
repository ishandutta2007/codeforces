#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MOD = 998244353;

int f[1010][4][2010];
int N,K;

int main()
{
	scanf("%d%d",&N,&K);
	memset(f,0,sizeof(f));
	f[1][0][1] = f[1][3][1] = f[1][1][2] = f[1][2][2] = 1;
	int ans = 0;
	for (int i=1;i<N;i++)
		for (int j=0;j<4;j++)
			for (int k=0;k<4;k++)
			{
				int delta;
				if (k == 0 || k == 3)
				{
					if (j == (k ^ 3))
						delta = 1;
					else
						delta = 0;
				}
				else
				{
					delta = ((j & 1) != (k & 1)) + ((j & 2) != (k & 2));
				}
				for (int l=1;l<=2*i;l++)
				{
					f[i+1][k][l + delta] += f[i][j][l];
					if (f[i+1][k][l + delta] >= MOD)
						f[i+1][k][l + delta] -= MOD;
				}
			}
	for (int i=0;i<4;i++)
		ans = (ans + f[N][i][K]) % MOD;
	printf("%d\n",ans);
}