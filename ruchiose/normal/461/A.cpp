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

const int MAXN = 300010;

int N, A[MAXN];

int main()
{
    scanf("%d", &N);
    int i;
    fortodo(i, 1, N) scanf("%d", &A[i]);
    sort(A + 1, A + N + 1);
    if (N == 1)
        printf("%d\n", A[1]);
    else
        {
            i64 sum = - A[N];
            fortodo(i, 1, N)
                sum += (i + 1ll) * A[i];
            cout << sum << endl;
        }
}