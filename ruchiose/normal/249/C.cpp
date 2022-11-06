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

const int MAXN = 100010;
const int MAXA0 = 110;

int N, A0[MAXN], A[MAXN], M;
d64 p[MAXN][MAXA0], ans;

void Move(int u, int v)
{
    d64 nxtp[MAXA0];
    int i;
    fortodo(i, 1, A0[u]) nxtp[i] = 0;
    nxtp[0] = p[u][0];
    fortodo(i, 1, A0[u])
        {
            nxtp[i - 1] += p[u][i] * i / A[u];
            nxtp[i] += p[u][i] * (A[u] - i) / A[u];
        }
    A[u]--; //A[v]++;
    fortodo(i, 0, A0[u]) p[u][i] = nxtp[i];
}

int main()
{
    scanf("%d", &N);
    int i, j;
    fortodo(i, 1, N)
        {
            scanf("%d", &A0[i]);
            A[i] = A0[i];
        }
    fortodo(i, 1, N)
        {
            fortodo(j, 0, A0[i] - 1) p[i][j] = 0;
            p[i][A0[i]] = 1;
        }
    ans = 0;
    fortodo(i, 1, N) ans += p[i][0];
    scanf("%d", &M);
    fortodo(i, 1, M)
        {
            int u, v, k;
            scanf("%d%d%d", &u, &v, &k);
            ans -= p[u][0];
            for (int kk = k; kk; kk--) Move(u, v);
            ans += p[u][0];
            A[v] += k;
            printf("%.14f\n", double(ans));
        }
}