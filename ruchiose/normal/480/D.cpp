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

const int MAXN = 510;
const int MAXT = MAXN << 1;

int N, S0, T;
int I[MAXN], O[MAXN], W[MAXN], S[MAXN], V[MAXN];
int sib[MAXN], snr[MAXT];

/*
int tp[MAXN], idg[MAXN];
bool Greater[MAXN][MAXN];

#include<queue>

void Topsort()
{
    tp[0] = 0;
    int i, j;
    fortodo(i, 1, N)
        fortodo(j, 1, N)
            Greater[i][j] = ((i != j) && (I[i] <= I[j]) && (O[i] >= O[j]));
    queue<int> Q;
    while (Q.size()) Q.pop();
    fortodo(i, 1, N)
        {
            idg[i] = 0;
            fortodo(j, 1, N)
                if (Greater[j][i])
                    idg[i]++;
            if (idg[i] == 0) Q.push(i);
        }
    while (Q.size())
        {
            int u = Q.front();
            tp[++tp[0]] = u;
            Q.pop();
            fortodo(i, 1, N)
                if (Greater[u][i])
                    {
                        idg[i]--;
                        if (idg[i] == 0)
                            Q.push(i);
                    }
        }
}
*/

int dp[MAXN][1010];

int DP(int idx, int s)
{
    s = min(s - W[idx], S[idx]);
    if (s < 0) return 0;
    if (dp[idx][s] != -1) return dp[idx][s];
    int r[1010], i;
    fortodo(i, I[idx], O[idx]) r[i] = 0;
    fortodo(i, I[idx], O[idx] - 1)
        {
            r[i + 1] = max(r[i + 1], r[i]);
            for (int E = snr[i]; E; E = sib[E])
                if ((E != idx) && (O[E] <= O[idx]))
                    r[O[E]] = max(r[O[E]], r[i] + DP(E, s));
        }
    return dp[idx][s] = (r[O[idx]] + V[idx]);
}

int main()
{
    int i, j;
    scanf("%d%d", &N, &S0);
    fortodo(i, 1, N)
        scanf("%d%d%d%d%d", &I[i], &O[i], &W[i], &S[i], &V[i]);
    N++;
    I[N] = 0; T = O[N] = 2 * N + 1;
    W[N] = 0; S[N] = S0; V[N] = 0;
    fortodo(i, 0, T) snr[i] = 0;
    fortodo(i, 1, N)
        {
            sib[i] = snr[I[i]];
            snr[I[i]] = i;
        }
    fortodo(i, 1, N)
        fortodo(j, 0, 1000)
            dp[i][j] = -1;
    printf("%d\n", DP(N, S0));
}