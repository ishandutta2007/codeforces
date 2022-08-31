#include <iostream>
#include <iomanip>
#include <map>
#include <queue>
#include <algorithm>
#include <string>
#include <set>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;
const int MAXN = 200100;

int N;
ll C;
ll sz[MAXN];
ll hsz[MAXN]; // i-i+1 pairs
ll res[MAXN];
ll psum[MAXN];

pair <int, ll> v[MAXN]; // loc, cscore (decreasing)

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> N >> C;
    for (int i = 0; i < 2 * N - 1; i++)
    {
        if (i % 2 == 0)
            cin >> sz[i / 2];
        else
            cin >> hsz[i / 2];
    }

    int lo = 0;
    int vstart = 0, vend = 1;
    v[0] = make_pair (-1, 0);
    ll bsum = 0;
    ll rsum = 0;
    ll cscore = 0;

    ll tot = 0;
    for (int i = 0; i < N; i++)
    {
        ll ans = min (C, sz[i]);
        bsum += sz[i];
        while (true)
        {
            if (bsum >= C)
            {
                ans = max (ans, C - rsum);
                while (vstart < vend && v[vstart].first <= lo - 1)
                    vstart++;
            }
            if (bsum - sz[lo] - hsz[lo] >= C)
            {
                bsum -= sz[lo] + hsz[lo];
                rsum -= res[lo];
                while (vstart < vend && v[vstart].first <= lo)
                    vstart++;
                lo++;
            }
            else
                break;
        }
        //if (vstart < vend && bsum >= C && v[vstart].first == lo)
        //    vstart++;

        //cout << vstart << " " << v[vstart].second << " " << cscore << "\n";
        if (vstart < vend)
            ans = max (ans, sz[i] + cscore - v[vstart].second);
        ans = min (C, ans);
        //cout << ans << "\n";
        tot += ans;
        res[i] = ans;
        cscore += sz[i] + hsz[i] - res[i];
        psum[i] = cscore;
        bsum += hsz[i];
        rsum += res[i];

        while (vstart < vend)
        {
            if (v[vend - 1].second >= cscore)
                vend--;
            else
                break;
        }
        v[vend++] = make_pair (i, cscore);
    }

    cout << tot << "\n";
    return 0;
}