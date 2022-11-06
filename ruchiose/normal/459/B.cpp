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

int maxv = 0, maxc = 0, minv = int(1e+9)+10, minc = 0;

int main()
{
    int N;
    for (scanf("%d", &N); N; N--)
        {
            int v;
            scanf("%d", &v);
            if (v > maxv) maxv = v, maxc = 0;
            if (v ==maxv) maxc++;
            if (v < minv) minv = v, minc = 0;
            if (v ==minv) minc++;
        }
    if (maxv == minv)
        printf("0 %I64d\n", maxc * (maxc - 1LL) / 2);
    else
        printf("%d %I64d\n", maxv - minv, (maxc * 1LL) * minc);
}