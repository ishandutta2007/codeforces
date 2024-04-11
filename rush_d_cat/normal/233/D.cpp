#include <iostream>
#include <cstdio>
using namespace std;
typedef long long LL;
const LL P = 1000000007;
const int NICO = 102;
LL C[102][102], A[102][102];
LL n, m, k;
LL dp[102][100002];
LL sum[100002];
LL max(LL x, LL y) {return x>y?x:y;}

LL pow(LL a, LL n)
{
    LL ret = 1;
    while(n)
    {
        if(n & 1)
        {
            ret = (ret * a);
            ret %= P;
        }
        a = a * a % P;
        n >>= 1;
    }
    return ret;
}

void init()
{
    for(int i=0;i<NICO;i++) dp[i][0] = C[i][0] = 1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            C[i][j] = (C[i-1][j] + C[i-1][j-1])%P;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            A[i][j] = pow(C[n][j], (m+n-i)/n);
        }
    }
}

int main() 
{
    cin >> n >> m >> k;
    init();
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i*n;j++)
        {
            for(int k=max(j-n, 0);k<=j;k++)
            {
                dp[i][j] += dp[i-1][k]*A[i][j-k]%P;
                dp[i][j] %= P;
            }
        }
    }
    cout << dp[n][k] << endl;
}