#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define i64 long long
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

int N, K, i;

int main()
{
    scanf("%d%d", &N, &K);
    if (N / 2 > K)
        {
            printf("-1\n");
            return 0;
        }
    if (N == 1)
        {
            printf("%d\n", (K) ? -1 : 1);
            return 0;
        }
    int c, major, minor, mjc, mnc;
    c = N / 2;
    minor = K / c;
    major = minor + 1;
    mjc = K % c;
    mnc = c - mjc;
    fortodo(i, 1, mnc) printf("%s%d %d", (i == 1) ? "" : " ", minor * i * 2, minor * (i * 2 + 1));
    int divs = 400000000;
    divs /= major;
    divs *= major; divs += major;
    fortodo(i, 1, mjc) printf(" %d %d", divs + major * i * 2, divs + major * (i * 2 + 1));  
    if (N & 1)
        printf(" 800000001\n");
    else
        printf("\n");
}