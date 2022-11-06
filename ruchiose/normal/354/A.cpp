#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define i64 long long
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

const int MAXN = 100010;

int N, L, R, QL, QR;
int W[MAXN];
int Prefix[MAXN], Suffix[MAXN];

int main()
{
    scanf("%d%d%d%d%d", &N, &L, &R, &QL, &QR);
    int i;
    fortodo(i, 1, N) scanf("%d", &W[i]);
    Prefix[0] = 0;
    fortodo(i, 1, N) Prefix[i] = Prefix[i - 1] + W[i];
    Suffix[N + 1] = 0;
    for (i = N; i; i--) Suffix[i] = Suffix[i + 1] + W[i];
    int ans = 0x7FFFFFFF;
    fortodo(i, 0, N)
        if (i > N - i) // L
            ans = min(ans, Prefix[i] * L + Suffix[i + 1] * R + QL * max(0, i * 2 - N - 1));
        else
            ans = min(ans, Prefix[i] * L + Suffix[i + 1] * R + QR * max(0, N - i * 2 - 1));
    printf("%d\n", ans);
}