#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <cmath>

using namespace std;
typedef double ld;
typedef long long ll;
const int MAXN = 100100;

int N;
vector <int> edge[MAXN];
int par[MAXN];
double vv[MAXN];
double vtot[MAXN];

void flood (int cloc, int last)
{
    par[cloc] = last;
    for (int neigh : edge[cloc])
    {
        if (neigh == last) continue;
        flood (neigh, cloc);
        vtot[cloc] += 1.0 - vv[neigh];
    }
}

int main()
{    
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%lf", vv + i);

    for (int i = 0; i < N - 1; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    flood (0, -1);

    ld cres = 0;
    for (int i = 0; i < N; i++)
        cres += vtot[i] * vv[i];
    cres += (1. - vv[0]);

    int Q; scanf ("%d", &Q);
    for (int i = 0; i < Q; i++)
    {
        int x; ld val;
        scanf("%d %lf", &x, &val);
        ld vdiff = val - vv[x];
        cres += vdiff * vtot[x];
        if (x)
        {
            cres -= vdiff * vv[par[x]];
            vtot[par[x]] -= vdiff;
        }
        else
            cres -= vdiff;
        vv[x] = val;
        printf("%.6lf\n", (double) cres);
    }
    return 0;
}