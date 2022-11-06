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

const int MAXN = 110;
const int MAXM = 5500;

int N, M;
int u[MAXM], v[MAXM], c[MAXM];

int F[MAXN];

int Find(int x)
{
    return F[x] = ((F[x] == x) ? x : Find(F[x]));
}

double Tag[MAXN];

double fac[MAXN][MAXN], cns[MAXN];
int Z[MAXN], Z0;

void Gauss()
{
    int i, j, k;
    fortodo(i, 1, N)
        {
            fortodo(j, Z0 + 1, N)
                if (abs(fac[j][i]) > 1e-9)
                    break;
            if (j > N) continue;
            Z[++Z0] = i;
            fortodo(k, 1, N) swap(fac[j][k], fac[Z0][k]); swap(cns[j], cns[Z0]);
            double rate = 1.0 / fac[Z0][i];
            fortodo(j, 1, N) fac[Z0][j] *= rate; cns[Z0] *= rate;
            fortodo(j, Z0 + 1, N)
                {
                    rate = -fac[j][i];
                    fortodo(k, 1, N)
                        fac[j][k] += fac[Z0][k] * rate;
                    cns[j] += cns[Z0] * rate;
                }
        }
    for (i = Z0; i; i--)
        {
            Tag[Z[i]] = cns[i];
            fortodo(j, 1, i - 1)
                {
                    double rate = -fac[j][Z[i]];
                    fortodo(k, 1, N) fac[j][k] += rate * fac[i][k];
                    cns[j] += rate * cns[i];
                }
        }
}

int main()
{
    scanf("%d%d", &N, &M);
    int i, j;
    fortodo(i, 1, M) scanf("%d%d%d", &u[i], &v[i], &c[i]);
    fortodo(i, 1, N) F[i] = i;
    fortodo(i, 1, M)
        F[Find(u[i])] = Find(v[i]);
    fortodo(i, 1, N)
        if (Find(i) != Find(1))
            Tag[i] = 0;
    if (Find(N) != Find(1))
        {
            fortodo(i, 0, M) puts("0");
            return 0;
        }
    fortodo(i, 1, N)
        fortodo(j, 1, N)
            fac[i][j] = 0;
    fortodo(i, 1, M)
        {
            fac[u[i]][u[i]]++;
            fac[u[i]][v[i]]--;
            fac[v[i]][u[i]]--;
            fac[v[i]][v[i]]++;
        }
    fortodo(i, 1, N) fac[1][i] = (i == 1) ? 1 : 0;
    fortodo(i, 1, N) fac[N][i] = (i == N) ? 1 : 0;
    fortodo(i, 1, N) cns[i] = (i == N) ? 1 : 0;
    Gauss();
    double rate = 1e+9;
    fortodo(i, 1, M)
        if ((Find(1) == Find(u[i])) && (abs(Tag[u[i]] - Tag[v[i]]) > 1e-9))
            rate = min(rate, abs(c[i] / (Tag[u[i]] - Tag[v[i]])));
    double tot = 0;
    fortodo(i, 1, M)
        {
            if (u[i] == 1) tot += (Tag[v[i]] - Tag[u[i]]) * rate;
            if (v[i] == 1) tot -= (Tag[v[i]] - Tag[u[i]]) * rate;
        }
    printf("%.8f\n", tot);
    fortodo(i, 1, M)
        printf("%.8f\n", (Tag[v[i]] - Tag[u[i]]) * rate);
}