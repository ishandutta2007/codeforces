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

int Euclid(int a, int b)
{
    return (b) ? Euclid(b, a % b) : a;
}

int Qipow(i64 x, i64 t, i64 p)
{
    i64 r = 1;
    for (; t; t >>= 1)
        {
            if (t & 1) r = (r * x) % p;
            x = (x * x) % p;
        }
    return int(r);
}

int N, T, P, A[10010];
int Divisor[2333];
int Phi[2333];
bool OK[2333];

int main()
{
    int M;
    scanf("%d%d%d", &N, &M, &P);
    T = P - 1;
    int i, j;
    fortodo(i, 1, N) scanf("%d", &A[i]);
    for (; M; M--)
        {
            int u;
            scanf("%d", &u);
            T = Euclid(T, u);
        }
    fortodo(i, 1, N) A[i] = Qipow(A[i], T, P);
    Divisor[0] = 0;
    for (i = 1; i * i <= P - 1; i++)
        if ((P - 1) % i == 0)
            {
                Divisor[++Divisor[0]] = i;
                if (i * i != P - 1)
                    Divisor[++Divisor[0]] = (P - 1) / i;
            }
    sort(Divisor + 1, Divisor + Divisor[0] + 1);
    fortodo(i, 1, Divisor[0])
        {
            Phi[i] = Divisor[i];
            fortodo(j, 1, i - 1)
                if (Divisor[i] % Divisor[j] == 0)
                    Phi[i] -= Phi[j];
        }
    fortodo(i, 1, Divisor[0]) OK[i] = false;
    fortodo(i, 1, N)
        {
            fortodo(j, 1, Divisor[0])
                if (Qipow(A[i], Divisor[j], P) == 1)
                    break;
            OK[j] = true;
        }
    fortodo(i, 1, Divisor[0])
        fortodo(j, 1, i - 1)
            if (Divisor[i] % Divisor[j] == 0)
                OK[j] |= OK[i];
    int ans = 0;
    fortodo(i, 1, Divisor[0])
        if (OK[i])
            ans += Phi[i];
    printf("%d\n", ans);
}