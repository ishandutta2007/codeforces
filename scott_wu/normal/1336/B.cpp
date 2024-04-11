#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N[3];
vector <ll> v[3];

ll sq (ll x) {return x * x;}

ll test (ll x, ll y, ll z)
{
    if (y < 0 || y > 1.1e9) return 8e18;
    if (z < 0 || z > 1.1e9) return 8e18;
    return sq (x - y) + sq (x - z) + sq (y - z);
}

void gogo()
{
    cin >> N[0] >> N[1] >> N[2];
    for (int i = 0; i < 3; i++)
    {
        v[i].clear();
        v[i].push_back(-1e9);
        v[i].push_back(2e9);
        for (int j = 0; j < N[i]; j++)
        {
            ll x; cin >> x;
            v[i].push_back(x);
        }
        sort (v[i].begin(), v[i].end());
    }

    ll ans = 8e18;
    for (int i = 0; i < 3; i++)
    {
        int j = (i + 1) % 3, k = (i + 2) % 3;
        for (ll x : v[i])
        {
            if (x < 0 || x > 1.1e9) continue;
            auto it = lower_bound(v[j].begin(), v[j].end(), x);
            auto it2 = lower_bound(v[k].begin(), v[k].end(), x);

            ans = min (ans, test (x, *it, *it2));
            ans = min (ans, test (x, *(it-1), *it2));
            ans = min (ans, test (x, *it, *(it2-1)));
            ans = min (ans, test (x, *(it-1), *(it2-1)));
        }
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    for (int i = 0; i < T; i++)
        gogo();
}