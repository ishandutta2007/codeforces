#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define i64 long long
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

const i64 MOD = 1000000007;
const i64 MAXN = 100010;

i64 Qipow(i64 b, i64 t)
{
    i64 a = 1;
    for (; t; t >>= 1)
        {
            if (t & 1) a = (a * b) % MOD;
            b = (b * b) % MOD;
        }
    return a;
}

int Q, F, N;
i64 fact[MAXN], ifct[MAXN], miu[MAXN];

i64 C(int n, int m)
{
    return (fact[n] * ifct[m] % MOD) * ifct[n - m] % MOD;
}

i64 Y(int n, int m)
{
    if (n < m) return 0;
    return C(n - 1, m - 1);
}

int main()
{
    scanf("%d", &Q);
    fact[0] = 1;
    int i, j;
    fortodo(i, 1, 100000) fact[i] = fact[i - 1] * i % MOD;
    fortodo(i, 0, 100000) ifct[i] = Qipow(fact[i], MOD - 2);
    miu[1] = 1;
    fortodo(i, 2, 100000)
        {
            for (j = 2; j * j <= i; j++) if (i % j == 0) break;
            if (j * j > i) j = i;
            if ((i / j) % j == 0)
                miu[i] = 0;
            else
                miu[i] = (miu[i / j]) ? (MOD - miu[i / j]) : 0;
        }
    for (; Q; Q--)
        {
            scanf("%d%d", &N, &F);
            i64 ans = 0;
            for (int i = 1; i * i <= N; i++)
                if (N % i == 0)
                    {
                        ans += miu[i] * Y(N / i, F);
                        if (N != i * i)
                            ans += miu[N / i] * Y(i, F);
                        ans %= MOD; 
                    }
            cout << ans << endl;
        }
}