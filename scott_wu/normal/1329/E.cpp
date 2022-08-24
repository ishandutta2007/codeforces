#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N, K;
int M;
vector <ll> v;
vector <pair <ll, ll> > vp;

ll gcost (ll X) // min # moves to get score <= X
{
    ll res = 0;
    for (ll c : v)
        res += (c - 1) / X;
    return res;
}

ll rcost (ll X) // max # moves while keeping score >= X
{
    ll res = 0;
    for (ll c : v)
    {
        if (c < X) return -1e18;
        res += c / X - 1;
    }
    return res;
}

void gogo()
{
    cin >> N >> M >> K;

    v.clear();
    ll lv = 0;
    for (int i = 0; i < M; i++)
    {
        ll x; cin >> x;
        v.push_back (x - lv);
        lv = x;
    }
    v.push_back (N - lv);

    sort (v.begin(), v.end());
    //for (ll x : v) cout << x << "\n";

    ll lo = 1, hi = N;
    while (lo < hi)
    {
        ll mid = (lo + hi) / 2;
        if (gcost (mid) > K)
            lo = mid + 1;
        else
            hi = mid;
    }

    ll rlo = 1, rhi = N;
    while (rlo < rhi)
    {
        ll mid = (rlo + rhi + 1) / 2;
        if (rcost (mid) < K)
            rhi = mid - 1;
        else
            rlo = mid;
    }

    vp.clear();
    ll ezmax = 0, ezmin = rlo;
    for (ll X : v)
    {
        ll nmove = (X - 1) / lo;
        ezmax = max (ezmax, (X - 1) / (nmove + 1) + 1);
        ezmin = min (ezmin, X / (nmove + 1));
        if (nmove)
        {
            ll chi = (X - 1) / nmove + 1;
            ll clo = X / (nmove + 1);

            vp.push_back (make_pair (chi, clo));
        }
    }
    sort (vp.begin(), vp.end());
    reverse (vp.begin(), vp.end());

    //cout << lo << " " << rlo << " " << ezmax << " " << ezmin << "\n";
    ll ans = ezmax - ezmin, cmin = rlo;
    for (int i = 0; i < vp.size(); i++)
    {
        ans = min (ans, vp[i].first - cmin);
        cmin = min (cmin, vp[i].second);
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);

    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        gogo();
    }
}