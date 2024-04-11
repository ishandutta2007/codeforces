#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <deque>

using namespace std;
typedef long long ll;
const int MAXN = 1000100;

int n, m;
int anum[2 * MAXN], bnum[MAXN];
int loc[MAXN];
int best;
ll poss[2*MAXN];
//vector <ll> poss;
//deque <ll> poss;

int main()
{
    for (int i = 0; i < MAXN; i++)
        loc[i] = -1;
    best = 0;
    scanf ("%d %d", &n, &m);
    //cout << n << " " << m << "\n";
    //cin >> n >> m;
    for (int i = 0; i < n; i++)
        scanf ("%d", &anum[i]);
        //cin >> anum[i];
    for (int i = n; i < 2 * n; i++)
        anum[i] = anum[i-n];
    for (int i = 0; i < m; i++)
    {
        scanf ("%d", &bnum[i]);
        //cin >> bnum[i];
        loc[bnum[i]] = i;
    }
    ll mult = 0;
    int ploc = 0, pend = 0;
    for (int i = 0; i < 2 * n; i++)
    {
        if (loc[anum[i]] == -1)
        {
            ploc = pend;
            continue;
        }
        if (pend == ploc)
        {
            mult = 0;
            poss[pend] = loc[anum[i]]; pend++;
            best = max (best, pend - ploc);
            continue;
        }
        ll next = poss[pend-1] / m * m + loc[anum[i]];
        while (next < poss[pend-1])
            next += m;
        poss[pend] = next; pend++;
        while (poss[pend-1] - poss[ploc] >= m)
            ploc++;
        best = max (best, (int) pend - ploc);
    }
    cout << min (best, n) << "\n";
    //system ("Pause");
    return 0;
}