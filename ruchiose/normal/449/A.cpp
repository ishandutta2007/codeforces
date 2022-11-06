// Author: Ruchiose
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#define i64 long long
#define d64 long double
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

int N, M, K;

int main()
{
    scanf("%d%d%d", &N, &M, &K);
    i64 ans = 0;
    int s, e;
    if (N + M - 2 < K)
        {
            printf("-1\n");
            return 0;
        }
    for (s = 1; (s <= N) && (s <= K + 1); s = e + 1)
        {
            int r = N / s;
            e = min(K + 1, N / r);
            if (K - (s - 1) < M)
                ans = max(ans, r * (M / (K - s + 2ll)));
            if (K - (e - 1) < M)
                ans = max(ans, r * (M / (K - e + 2ll)));
        }
    cout << ans << endl;
}