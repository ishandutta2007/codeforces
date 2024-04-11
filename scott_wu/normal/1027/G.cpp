#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <set>

using namespace std;
typedef long long ll;
const int MAXF = 20;
const ll B = 1e4;

ll M, X;
vector <pair <ll, int> > v;
vector <pair <ll, ll> > vv[MAXF]; // order, denom

ll gcf (ll x, ll y)
{
    if (y == 0) return x;
    return gcf (y, x % y);
}

ll mult (ll x, ll y, ll m)
{
    if (y < B) return (x * y) % m;
    return (mult (x, y / B, m) * B + (x * (y % B))) % m;
}

ll mpow (ll e, ll m)
{
    ll cpow = X, res = 1;
    while (e)
    {
        if (e & 1)
            res = mult (res, cpow, m);
        cpow = mult (cpow, cpow, m);
        e /= 2;
    }
    return res;
}

vector <pair <ll, int> > factorize (ll c)
{
    vector <pair <ll, int> > res;
    for (int i = 2; i * (ll) i <= c; i++)
    {
        if (c % i == 0)
        {
            res.push_back(make_pair(i, 0));
            while (c % i == 0)
            {
                res.back().second++;
                c /= i;
            }
        }
    }
    if (c > 1)
    {
        res.push_back(make_pair (c, 1));
    }
    return res;
}

ll ans;

void dfs (int cloc, ll cord, ll ctot)
{
    if (cloc == v.size())
    {
        ans += ctot / cord;
        return;
    }

    for (int i = 0; i < vv[cloc].size(); i++)
    {
        ll nord = vv[cloc][i].first, ntot = vv[cloc][i].second;
        dfs (cloc + 1, cord / gcf (cord, nord) * nord, ctot * ntot);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> M >> X;
    v = factorize (M);
    for (int i = 0; i < v.size(); i++)
    {
        ll p = v[i].first;
        int c = v[i].second;
        ll cp = p, ccnt = p - 1;
        for (int j = 0; j <= c; j++)
        {
            if (!j)
            {
                vv[i].push_back(make_pair (1, 1));
                continue;
            }
            auto pf = factorize (ccnt);
            ll ctot = ccnt;
            for (int k = 0; k < pf.size(); k++)
            {
                ll cprime = pf[k].first;
                while (ctot % cprime == 0)
                {
                    if (mpow (ctot / cprime, cp) == 1)
                        ctot /= cprime;
                    else break;
                }
            }

            vv[i].push_back(make_pair (ctot, ccnt));
            ccnt *= p;
            cp *= p;
        }
    }

    dfs (0, 1, 1);
    cout << ans << "\n";
    return 0;
}