#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define i64 long long
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

const int MAXN = 100010;

int N, i, j, A[MAXN];

i64 Num, Den;

i64 Euclid(i64 a, i64 b)
{
    return (b) ? Euclid(b, a % b) : a;
}

int main()
{
    scanf("%d", &N);
    fortodo(i, 1, N) scanf("%d", &A[i]);
    sort(A + 1, A + N + 1);
    Num = 0ll; Den = N;
    fortodo(i, 1, N) Num += A[i] * (i * 2ll - N); // Check Forward
    fortodo(i, 1, N) Num += A[i] * (i * 2ll - N - 1); // Check Backward
    i64 E = Euclid(Num, Den);
    printf("%I64d %I64d\n", Num / E, Den / E);
}