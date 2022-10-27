/*
tags: [][dp]
hint 1: 
b[i]i
AA*b[i] = b[i+1]

hint 2:
1~9x*9


hint 3:


*/

#include <iostream>
using namespace std;
typedef long long LL;
const int MOD = 1000000000 + 7;
const int NICO = 50000 + 10;
int n, b, k, x, DIM;
int a[NICO], cnt[12];

struct M
{
    LL num[102][102];
};
M O, E;

void init()
{
    for(int i=0;i<DIM;i++)
    {
        for(int j=0;j<DIM;j++)
        {
            O.num[i][j] = 0;
            E.num[i][j] = (i==j)?1:0;
        }
    }
}

M mul(M A, M B)
{
    M C = O;
    for(int i=0;i<DIM;i++) 
    {
        for(int j=0;j<DIM;j++) 
        {     
            for(int k=0;k<DIM;k++)
            {
                C.num[i][j] += A.num[i][k] * B.num[k][j];
                C.num[i][j] %= MOD;
            }
        }
    }
    return C;
}

M mpow(M a, LL n)
{
    M ret = E;
    while(n)
    {
        if(n & 1)
        {
            ret = mul(ret, a);
        }
        a = mul(a, a);
        n >>= 1;
    }
    return ret;
}

int main()
{
    cin >> n >> b >> k >> x;
    DIM = x; init();
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        cnt[a[i]] ++;
    }
    M A = O;//
    for(int i=0;i<x;i++)
    {
        for(int j=0;j<x;j++)
        {
            for(int k=1;k<=9;k++)
            {
                if((10*i+k)%x == j)
                {
                    A.num[j][i] += cnt[k];
                    A.num[j][i] %= MOD;
                }
            }
        }
    }

    A = mpow(A, b);
    int ans = A.num[k][0];
    cout << ans << endl;
}