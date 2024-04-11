#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 200100;
const int P = (1 << 21);
const int MAXP = 2 * P + 100;

ll seg[MAXP];
ll sadd[MAXP];

void prop (int cloc)
{
    seg[cloc] += sadd[cloc];
    if (cloc < P)
    {
        sadd[2*cloc] += sadd[cloc];
        sadd[2*cloc+1] += sadd[cloc];
    }
    sadd[cloc] = 0;
}

void radd (int cloc, int lo, int hi, int rlo, int rhi, ll amt)
{
    prop (cloc);
    if (lo >= rlo && rhi >= hi)
    {
        sadd[cloc] += amt;
        prop (cloc);
        return;
    }
    if (hi < rlo || rhi < lo)
        return;

    int mid = (lo + hi) / 2;
    radd (2 * cloc, lo, mid, rlo, rhi, amt);
    radd (2 * cloc + 1, mid + 1, hi, rlo, rhi, amt);

    seg[cloc] = max (seg[2*cloc], seg[2*cloc+1]);
}

vector <pair <ll, pair <ll, ll> > > event;

int main()
{
    ios_base::sync_with_stdio(0);

    int N, M, Q;
    cin >> N >> M >> Q;
    for (int i = 0; i < N; i++)
    {
        ll a, c;
        cin >> a >> c;
        event.push_back (make_pair (2 * a, make_pair (-1, c)));
    }

    for (int i = 0; i < MAXP; i++)
        seg[i] = -1e12;
    for (int i = 0; i < M; i++)
    {
        ll b, c;
        cin >> b >> c;
        seg[P+2*b] = max (seg[P+2*b], -c);
    }
    for (int i = 2 * P - 2; i >= P; i--)
        seg[i] = max (seg[i], seg[i+1]);
    for (int i = P - 1; i >= 1; i--)
        seg[i] = max (seg[2*i], seg[2*i+1]);

    for (int i = 0; i < Q; i++)
    {
        ll x, y, p;
        cin >> x >> y >> p;
        event.push_back (make_pair (2 * x + 1, make_pair (2 * y + 1, p)));
    }

    sort (event.begin(), event.end());

    ll ans = -1e12;
    ll ptot = 0;
    for (auto it : event)
    {
        //cout << it.first << " " << it.second.first << " " << it.second.second << "\n";
        if (it.second.first == -1)
        {
            ll ccost = it.second.second;
            ans = max (ans, ptot + seg[1] - ccost);
        }
        else
        {
            ll cval = it.second.first, camt = it.second.second;
            radd (1, 0, P - 1, 0, cval, -camt);
            ptot += camt;
        }
    }

    cout << ans << "\n";
}