#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define i64 long long
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

int N, S, i, A[101];

int main()
{
    scanf("%d%d", &N, &S);
    fortodo(i, 1, N) scanf("%d", &A[i]);
    sort(A + 1, A + N + 1);
    fortodo(i, 1, N - 1) S -= A[i];
    if (S >= 0)
        printf("YES\n");
    else
        printf("NO\n");
}