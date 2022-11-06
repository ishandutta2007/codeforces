#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define i64 long long
#define fortodo(i, f, t) for (i = f; i <= t; i++)
#define mp make_pair
using namespace std;

int N, A[100010], B[100010], i, j;
i64 F[100010];

#define pii pair<int,i64>
#define d64 long double
pii W[100010], nxt;
int H, T;

i64 Cost(pii s, int Ai)
{
    return s.second + (i64)s.first * Ai;
}

bool Conv(pii a, pii b, pii c)
{
    d64 dxa = a.first - b.first;
    d64 dya = b.second - a.second;
    d64 dxc = b.first - c.first;
    d64 dyc = c.second - b.second;
    return (dxa * dyc > dxc * dya);
}

int main()
{
    scanf("%d", &N);
    fortodo(i, 1, N) scanf("%d", &A[i]);
    fortodo(i, 1, N) scanf("%d", &B[i]);
    F[1] = 0; H = T = 1;
    W[1] = mp(B[1], 0);
    fortodo(i, 2, N)
        {
            while ((T - H) && (Cost(W[H], A[i]) >= Cost(W[H + 1], A[i]))) H++;
            F[i] = Cost(W[H], A[i]);
            nxt = mp(B[i], F[i]);
            while ((T - H) && (!Conv(W[T - 1], W[T], nxt))) T--;
            W[++T] = nxt;
        }
    cout << F[N] << endl;
}