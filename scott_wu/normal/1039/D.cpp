#include <iostream>
#include <iomanip>
#include <fstream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <string>
#include <ctime>

using namespace std;
typedef long long ll;
const int MAXN = 100100;

int N;
vector <int> edge[MAXN];
int nord;
int ord[MAXN];
int par[MAXN];
int res[MAXN];

void flood (int cloc, int last)
{
    if (last != -1)
        par[nord] = ord[last];
    ord[cloc] = nord++;
    for (int i = 0; i < edge[cloc].size(); i++)
    {
        int neigh = edge[cloc][i];
        if (neigh == last) continue;
        flood (neigh, cloc);
    }
}

int ans;
int m1[MAXN], m2[MAXN];

int get_res (int K)
{
    ans = 0;
    for (int cloc = N - 1; cloc >= 0; cloc--)
    {
        if (m1[cloc] + m2[cloc] >= K)
            ans++;
        else
        {
            int p = par[cloc];
            if (m1[cloc] + 1 > m2[p])
            {
                m2[p] = m1[cloc] + 1;
                if (m2[p] > m1[p])
                    swap (m1[p], m2[p]);
            }
        }
        m1[cloc] = m2[cloc] = 0;
    }
    res[K] = ans;
    return ans;
}

void run (int lo, int hi, int rlo, int rhi)
{
    if (lo > hi) return;
    if (rlo == rhi)
    {
        for (int i = lo; i <= hi; i++)
            res[i] = rlo;
        return;
    }

    int mid = (lo + hi) / 2;
    int mval = get_res (mid);
    run (lo, mid - 1, mval, rhi);
    run (mid + 1, hi, rlo, mval);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N - 1; i++)
    {
        int x, y; cin >> x >> y;
        x--, y--;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }

    nord = 0;
    flood (0, -1);

    run (0, N - 1, 0, N);
    for (int i = 0; i < N; i++)
        cout << res[i] << "\n";
}