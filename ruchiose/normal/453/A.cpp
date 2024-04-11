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

int M, N;

int main()
{
    scanf("%d%d", &M, &N);
    double ans = 0;
    int i;
    fortodo(i, 1, M)
        ans += i * (pow(i * 1.0 / M, N) - pow((i - 1.0) / M, N));
    printf("%.11f\n", ans);
}