#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define i64 long long
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

int N, M, X, Y, A, B;

int Euclid(int a, int b)
{
    return (b) ? Euclid(b, a % b) : a;
}

int main()
{
    scanf("%d%d%d%d%d%d", &N, &M, &X, &Y, &A, &B);
    int E = Euclid(A, B);
    A /= E; B /= E;
    int F = min(N / A, M / B);
    int x1, y1;
    x1 = X - ((A * F + 1) / 2);
    y1 = Y - ((B * F + 1) / 2);
    if (x1 < 0) x1 = 0;
    if (y1 < 0) y1 = 0;
    if (x1 + A * F > N) x1 = N - A * F;
    if (y1 + B * F > M) y1 = M - B * F;
    printf("%d %d %d %d\n", x1, y1, x1 + A * F, y1 + B * F);
}