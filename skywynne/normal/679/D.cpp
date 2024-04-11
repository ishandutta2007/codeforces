#include<bits/stdc++.h>
#define ld long double
#define pb push_back
using namespace std;
const int N = 404;
int n, m, D[N][N];
ld Max, Prob[N], Best[N];
vector < int > U, Adj[N], C[N][N];
int main()
{
    scanf("%d%d", &n, &m);
    memset(D, 1, sizeof(D));
    for (int i = 1, v, u; i <= m; i++)
        scanf("%d%d", &v, &u), Adj[v].pb(u), Adj[u].pb(v), D[v][u] = D[u][v] = 1;
    for (int i = 1; i <= n; i++)
        D[i][i] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int h = 1; h <= n; h++)
                D[j][h] = min(D[j][h], D[j][i] + D[i][h]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            C[i][D[i][j]].pb(j);
    for (int i = 1; i <= n; i++)
    {
        ld sum = 0;
        for (int d = 0; d <= n && C[i][d].size(); d++)
        {
            U.clear();
            ld fd = (ld)1 / n;
            for (int h = 0; h <= n; h++)
                Prob[h] = 0;
            for (int &v : C[i][d])
                for (int &u : Adj[v])
                {
                    if (Prob[u] == 0)
                        U.pb(u);
                    Prob[u] += (ld)1 / n / Adj[v].size();
                }
            ld best = 0;
            for (int j = 1; j <= n; j++)
            {
                ld _sum = 0;
                for (int &u : U)
                    Best[D[j][u]] = max(Best[D[j][u]], Prob[u]);
                for (int &u : U)
                {
                    _sum += Best[D[j][u]];
                    Best[D[j][u]] = 0;
                }
                best = max(best, _sum);
            }
            sum += max(best, fd);
        }
        Max = max(Max, sum);
    }
    return !printf("%.10lf", (double)Max);
}