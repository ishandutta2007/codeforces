#include <cstdio>
#include <cstdint>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <deque>

using namespace std;

#define MAXN 110
#define F first
#define S second

bool inp[MAXN][MAXN][MAXN];
int n;
int gp[MAXN][MAXN];
int ngp[MAXN];
int par[MAXN];

void dfs(int k, int i)
{
    gp[k][i] = ngp[k];
    for (int j = 0; j < n; j++)
    {
        if (gp[k][j] == -1 && inp[k][i][j]) dfs(k, j);
    }
}

void conn(int k)
{
    for (int i = 0; i < n; i++) gp[k][i] = -1;

    ngp[k] = 0;
    for (int i = 0; i < n; i++)
    {
        if (gp[k][i] == -1)
        {
            dfs(k, i);
            ngp[k]++;
        }
    }
}

int dis[MAXN][MAXN];

bool validate()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dis[i][j] = n;
        }
        dis[i][i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        if (par[i] == -1) continue;
        dis[i][par[i]] = dis[par[i]][i] = 1;
    }
    for (int k = 0; k < n; k++)
    {
        for (int i =0; i<n;i++) for (int j = 0; j < n; j++) dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    }
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i <n; i++)
        {
            for (int j = 0; j<n; j++)
            {
                if ((dis[k][i] == dis[k][j]) != inp[k][i][j]) return false;
            }
        }
    }
    return true;
}

int main()
{
    int casN;
    scanf("%d", &casN);
    for (int cas = 0; cas < casN; cas++)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n-i-1; j++)
            {
                char t[MAXN];
                scanf("%s", t);

                for (int k = 0; k<n; k++)
                {
                    inp[k][i][i+j+1] = t[k] == '1';
                    inp[k][i+j+1][i] = t[k] == '1';
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                inp[j][i][i] = true;
            }
        }

        for (int i = 0; i < n; i++)
        {
            conn(i);
        }
        for (int i =0; i < n; i++) par[i] = -1;

        bool ans = true;
        for (int iter = 0; iter < n-1; iter++)
        {
#if 0
            printf("iter %d\n", iter);
            for (int i = 0; i < n; i++)
            {
                if (par[i] != -1) printf("---P");
                else {
                    printf("G%d ", ngp[i]);
                for (int j = 0; j < n; j++)
                {
                    if (par[j] != -1) printf("P ");
                    else printf("%d ", gp[i][j]);
                }
                }
                printf("\n");
            }
#endif
            int L = -1;
            int minG = -1;
            for (int i = 0; i < n; i++)
            {
                if (par[i] == -1 && ngp[i] > minG)
                {
                    L = i;
                    minG = ngp[i];
                }
            }
            //printf("%d\n", L);

            if (iter == n-2)
            {
                for (int i = 0; i < n; i++)
                {
                    if (par[i] == -1 && i != L)
                    {
                        par[L] = i;
                    }
                }
                break;
            }

            int P = -1;
            for (int i = 0; i < n; i++)
            {
                if (i == L || par[i] != -1) continue;
                if (ngp[i] != ngp[L]-1) continue;

                int lgp[MAXN];
                int igp[MAXN];
                int lmp[MAXN];
                int imp[MAXN];
                int lmn = 0;
                int imn = 0;
                for (int j = 0; j < n; j++)
                {
                    lmp[j] = -1;
                    imp[j] = -1;
                }
                bool ok = true;
                for (int j = 0; j < n; j++)
                {
                    if (j == i || j == L || par[j] != -1)
                    {
                        continue;
                    }
                    if (lmp[gp[L][j]] == -1)
                    {
                        lmp[gp[L][j]] = lmn++;
                    }
                    if (imp[gp[i][j]] == -1)
                    {
                        imp[gp[i][j]] = imn++;
                    }
                    lgp[j] = lmp[gp[L][j]];
                    igp[j] = imp[gp[i][j]];

                    if (lgp[j] != igp[j])
                    {
                        //printf("(%d %d): %d %d %d\n", L, i, j, lgp[j], igp[j]);
                        ok = false;
                        break;
                    }
                }

                if (!ok) continue;

                if (lmp[gp[L][i]] != -1 || imp[gp[i][L]] == -1)
                {
                    //printf("(%d %d): %d %d\n", L, i, lmp[gp[L][i]], lmp[gp[L][i]]);
                    ok = false;
                    continue;
                }

                P = i;
                break;
            }

            if (P == -1)
            {
                //printf("np\n");
                ans = false;
                break;
            }
            par[L] = P;
            //printf("%d->%d", L, P);

            for (int i = 0; i < n ; i++)
            {
                if (par[i] != -1) continue;
                int cnt = 0;
                for (int j = 0; j < n; j++)
                {
                    if (par[j] != -1) continue;
                    if (gp[i][j] == gp[i][L])
                    {
                        cnt = 1;
                        break;
                    }
                }
                if (!cnt)
                {
                    ngp[i]--;
                    for (int j = 0; j < n; j++)
                    {
                        if (par[j] != -1) continue;
                        if (gp[i][j] == ngp[i]) gp[i][j] = gp[i][L];
                    }
                }
            }
        }
        if (ans)
        {
            ans = validate();
        }

        if (ans)
        {
            printf("Yes\n");
            for (int i = 0; i < n; i++)
            {if (par[i] == -1) continue;
                printf("%d %d\n", i+1, par[i]+1);
            }
        }
        else
        {
            printf("No\n");
        }
    }

    return 0;
}