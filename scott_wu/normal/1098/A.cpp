#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <cmath>

using namespace std;
typedef long long ll;
const int MAXN = 100100;

int N;
int par[MAXN];
ll a[MAXN];
ll ans;
vector <int> child[MAXN];
bool bad;

void flood (int cloc, ll csum)
{
    if (a[cloc] == -1)
    {
        ll bhi = 1e10;
        for (int neigh : child[cloc])
        {
            bhi = min (bhi, a[neigh]);
        }
        if (bhi > 9e9)
        {
            bhi = csum;
        }
        if (bhi < csum)
            bad = true;
        a[cloc] = bhi;
        ans += bhi - csum;
        csum = bhi;
    }
    else
    {
        if (a[cloc] < csum)
            bad = true;
        else
        {
            ans += a[cloc] - csum;
            csum = a[cloc];
        }
    }

    for (int neigh : child[cloc])
        flood (neigh, csum);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i < N; i++)
    {
        cin >> par[i];
        par[i]--;
        child[par[i]].push_back(i);
    }
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }

    bad = false;
    ans = 0;
    flood (0, 0);

    if (bad) cout << "-1\n";
    else cout << ans << "\n";
}