#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXM = 10100;
const int MAXG = 1100;

int N, M;
int d[MAXM];
bool seen[MAXM][MAXG];
int cdist[MAXM];

int G, R;

vector <int> q;
vector <int> nb;

void gogo (int cloc, int ctime)
{
    if (seen[cloc][ctime]) return;
    seen[cloc][ctime] = true;
    if (!ctime)
    {
        nb.push_back(cloc);
        return;
    }

    if (cloc > 0 && d[cloc] - d[cloc-1] <= ctime)
        gogo (cloc - 1, ctime - (d[cloc] - d[cloc-1]));
    if (cloc < M - 1 && d[cloc+1] - d[cloc] <= ctime)
        gogo (cloc + 1, ctime - (d[cloc+1] - d[cloc]));
}

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> N >> M;
    for (int i = 0; i < M; i++)
        cin >> d[i];
    sort (d, d + M);
    cin >> G >> R;

    for (int i = 0; i < MAXM; i++)
    {
        cdist[i] = 1e9;
        for (int j = 0; j < MAXG; j++)
            seen[i][j] = false;
    }
    cdist[0] = 0;
    seen[0][0] = true;
    q.push_back(0);

    for (int nq = 0; nq < q.size(); nq++)
    {
        int cloc = q[nq];

        nb.clear();
        gogo (cloc, G);
        for (int x : nb)
        {
            cdist[x] = cdist[cloc] + 1;
            q.push_back(x);
        }
    }

    int ans = 1e9;
    for (int i = 0; i < M; i++)
    {
        if (N - d[i] <= G && cdist[i] < 1e8)
            ans = min (ans, (N - d[i]) + cdist[i] * (G + R));
    }
    if (ans > 9e8) cout << "-1\n";
    else cout << ans << "\n";
}