#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define i64 long long
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

const i64 MOD = 1000000009ll;

i64 N, M, K, R;

#define pii pair<i64,i64>
#define mp make_pair

pii operator *(pii a, pii b)
{
    return mp(a.first * b.first % MOD, (a.second * b.first + b.second) % MOD);
}

int main()
{
    scanf("%I64d%I64d%I64d", &N, &M, &K);
    R = N - M;
    if ((R + 1) * (K - 1) >= M)
        {
            printf("%I64d\n", M);
            return 0;
        }
    i64 Relaxed = R * (K - 1);
    i64 B = (M - Relaxed) / K;
    pii Bas = mp(2, 2 * K % MOD);
    pii Ans = mp(1, 0);
    for (; B; B >>= 1)
        {
            if (B & 1) Ans = Ans * Bas;
            Bas = Bas * Bas;
        }
    i64 S = (Ans.second + (M - Relaxed) % K + Relaxed) % MOD;
    printf("%I64d\n", S);
}