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

const int MAXN = int(1e+6) + 10;

int N, A[MAXN], S[MAXN], P[MAXN], Q[MAXN], sh[MAXN];
int V[MAXN];

void init()
{
    int i;
    fortodo(i, 1, N) V[i] = 0;
}

void att(int x)
{
    for (; x <= N; x += x & (-x)) V[x]++;
}

int qry(int x)
{
    int ret = 0;
    for (; x; x -= x & (-x)) ret += V[x];
    return ret;
}

int main()
{
    scanf("%d", &N);
    int i;
    fortodo(i, 1, N) scanf("%d", &A[i]);
    fortodo(i, 1, N) S[i] = A[i];
    sort(S + 1, S + N + 1);
    fortodo(i, 1, N) A[i] = lower_bound(S + 1, S + N + 1, A[i]) - S;
    fortodo(i, 1, N) sh[i] = 0;
    fortodo(i, 1, N) P[i] = ++sh[A[i]];
    fortodo(i, 1, N) sh[i] = 0;
    for (i = N; i; i--) Q[i] = ++sh[A[i]];
    i64 ans = 0;
    init();
    for (i = N; i; i--)
        {
            ans += qry(P[i] - 1);
            att(Q[i]);
        }
    cout << ans << endl;
}