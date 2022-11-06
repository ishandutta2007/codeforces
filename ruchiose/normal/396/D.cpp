#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define i64 long long
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

const i64 MOD = 1000000007;

i64 Qipow(i64 B, i64 T)
{
    i64 A = 1;
    for (; T; T >>= 1)
        {
            if (T & 1) A = (A * B) % MOD;
            B = (B * B) % MOD;
        }
    return A;
}

int N, i, j, A[1000010];
i64 iv2, iv4, ANS, Pref, fact[1000010];

i64 Average(int n)
{
    return (iv4 * (((i64)n * n - n) % MOD)) % MOD;
}

int Dt[1000010];

void att(int x, int v)
{
    for (; x <= N; x += x & (-x)) Dt[x] += v;
}

int qry(int x)
{
    int r = 0;
    for (; x; x -= x & (-x)) r += Dt[x];
    return r;
}

int main()
{
    scanf("%d", &N);
    fortodo(i, 1, N) scanf("%d", &A[i]);
    iv2 = Qipow(2, MOD - 2);
    iv4 = Qipow(4, MOD - 2);
    fortodo(i, 1, N) Dt[i] = i & (-i);
    ANS = Pref = 0;
    fact[0] = 1;
    fortodo(i, 1, N) fact[i] = (fact[i - 1] * i) % MOD;
    fortodo(i, 1, N)
        {
            att(A[i], -1);
            int cntpre = qry(A[i]);
            i64 preAvg = (Pref + ((cntpre - 1) * iv2) % MOD + Average(N - i)) % MOD;
            ANS += (preAvg * cntpre) % MOD * fact[N - i];
            ANS %= MOD;
            Pref = (Pref + cntpre) % MOD;
        }
    ANS += Pref;
    ANS %= MOD;
    cout << ANS << endl;
}