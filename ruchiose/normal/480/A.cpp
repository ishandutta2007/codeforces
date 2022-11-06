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

const int MAXN = 5010;

int N, A[MAXN], B[MAXN], S[MAXN];

bool cmp_Aaz(int i, int j)
{
    return (A[i] == A[j]) ? (B[i] < B[j]) : (A[i] < A[j]);
}

int main()
{
    scanf("%d", &N);
    int i;
    fortodo(i, 1, N) scanf("%d%d", &A[i], &B[i]);
    fortodo(i, 1, N) S[i] = i;
    sort(S + 1, S + N + 1, cmp_Aaz);
    int Maxdate = 0;
    fortodo(i, 1, N)
        {
            int s = S[i];
            if (Maxdate <= B[s])
                Maxdate = B[s];
            else
                Maxdate = A[s];
        }
    printf("%d\n", Maxdate);
}