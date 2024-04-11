#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;
typedef long long ll;
const int MAXN = 50100;
const int MAXK = 510;

int n, k;
vector <int> edge[MAXN];
ll ncow[MAXN];
int under[MAXN][MAXK];
int total[MAXN][MAXK];
int parent[MAXN];

void flood (int cur, int last)
{
    parent[cur] = last;
    for (int i = 0; i < edge[cur].size(); i++)
        if (edge[cur][i] != last)
            flood (edge[cur][i], cur);
}

void usolve (int cur)
{
    under[cur][0] = ncow[cur];
    for (int i = 0; i < edge[cur].size(); i++)
        if (edge[cur][i] != parent[cur])
        {
            usolve (edge[cur][i]);
            for (int j = 1; j <= k; j++)
                under[cur][j] += under[edge[cur][i]][j-1];
        }
}

void tsolve (int cur)
{
    if (cur == 0)
    {
        for (int i = 0; i <= k; i++)
            total[cur][i] = under[cur][i];
    }
    else
    {
        int par = parent[cur];
        for (int i = 0; i < k; i++)
        {
            total[cur][i+1] = total[par][i] + under[cur][i+1];
            if (i >= 1)
                total[cur][i+1] -= under[cur][i-1];
        }
        total[cur][0] = under[cur][0];
    }
    for (int i = 0; i < edge[cur].size(); i++)
        if (edge[cur][i] != parent[cur])
            tsolve (edge[cur][i]);
}

int main()
{
    for (int i = 0; i < MAXN; i++)
        for (int j = 0; j < MAXK; j++)
            under[i][j] = total[i][j] = 0;
    cin >> n >> k;
    for (int i = 0; i < n - 1; i++)
    {
        int t, t2;
        cin >> t >> t2;
        t--; t2--;
        edge[t].push_back (t2);
        edge[t2].push_back (t);
    }
    for (int i = 0; i < n; i++)
        ncow[i] = 1;
    flood (0, -1);
    usolve (0);
    tsolve (0);
    
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += total[i][k];
    }
    cout << sum / 2 << "\n";
    //system ("Pause");
    return 0;
}