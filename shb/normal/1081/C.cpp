#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N,M,K;
LL f[2010][2010];
const int MOD = 998244353;

int main()
{
    scanf("%d%d%d",&N,&M,&K);
    f[1][0] = M;
    for (int i=2;i<=N;i++)
        for (int j=0;j<=K;j++)
        {
            f[i][j] = f[i-1][j];
            if (j > 0)
                f[i][j] += 1LL * (M-1) * f[i-1][j-1];
            f[i][j] %= MOD;
        }
    printf("%lld\n",f[N][K]);
}