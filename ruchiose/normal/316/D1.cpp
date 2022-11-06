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

const i64 MOD = int(1e+9) + 7;

int N;
i64 P[1000010];

int main()
{
    scanf("%d", &N);
    int C[3];
    C[1] = C[2] = 0;
    int i;
    fortodo(i, 1, N)
        {
            int u;
            scanf("%d", &u);
            C[u]++;
        }
    P[0] = P[1] = 1;
    fortodo(i, 2, C[1])
        P[i] = (P[i - 1] + (i - 1) * P[i - 2]) % MOD;
    i64 ans = P[C[1]];
    fortodo(i, 1, C[2])
        ans = ans * (C[1] + i) % MOD;
    cout << ans << endl;
}