#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;
const LL MOD = 1000000000 + 7;
const int NICO = 100;
const int MAKI = 100;

struct M
{
    LL a[NICO][NICO];
    M() { memset(a,0,sizeof(a)); }
};

int n, k;
LL s, c[NICO][NICO];

void init()
{
    n = 2*k+3;
    for(int i=0;i<=k;i++)
    {
        c[i][0] = c[i][i] = 1;
        for(int j=1;j<i;j++)
        {
            c[i][j] = c[i-1][j-1] + c[i-1][j];
        }
    }
}

M mul(M A , M B)
{
    M ans;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int t=0;t<n;t++)
            {
                ans.a[i][j] += A.a[i][t]*B.a[t][j];
                ans.a[i][j] %= MOD;
            }
        }
    }
    return ans;
}

M qpow(M A, LL t)
{
    M ans;
    for(int i=0;i<n;i++) ans.a[i][i] = 1;
    while(t) 
    {
        if(t&1) ans = mul(ans, A);
        A = mul(A, A);
        t /= 2;
    }
    return ans;
}

int main()
{
    cin >> s >> k, init();
    M A;
    for (int i = 0; i <= k; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            A.a[i][j] = A.a[i+k+1][j] = A.a[i][j+k+1] = c[i][j];
        }
    }
    A.a[2*k+2][k] = A.a[2*k+2][2*k+2] = 1;
    A = qpow(A, s);
    LL res = 0;
    for(int i=0;i<2*k+2;i++)
    {
        res = (res + A.a[2*k+2][i]) % MOD;
    }
    cout << res << endl;

}