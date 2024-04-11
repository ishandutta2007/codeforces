#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
long long factorials[5010];
long long binom[5010][5010];

long long conv(long long a, long long b)
{
    long long r = 0;
    long long x = max(a, b), y = min(a, b);
    for(int i = 0; i <= y; i++)
    {
        r = (r + ((binom[x][i] * binom[y][i])%MOD*factorials[i])%MOD)%MOD;
    }
    return r;
}

int main()
{

    factorials[0] = 1;
    binom[0][0] = 1;
    for(int i = 1; i <= 5000; i++)
    {
        factorials[i] = (i*factorials[i - 1])%MOD;
        binom[i][0] = binom[i][i] = 1;
    }
    for(int i = 1; i <= 5000; i++)
    {
        for(int j = 1; j < i; j++)
        {
            binom[i][j] = (binom[i - 1][j] + binom[i - 1][j - 1])%MOD;
        }
    }
    long long a, b, c, res = 1;
    cin >> a >> b >> c;
    res = (res * conv(a, b))%MOD;
    res = (res * conv(a, c))%MOD;
    res = (res * conv(b, c))%MOD;
    cout << res;
    return 0;
}