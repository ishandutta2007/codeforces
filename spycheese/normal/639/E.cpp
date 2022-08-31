#include <bits/stdc++.h>

#ifndef LOCAL
#define cerr dolor_sit_amet
#endif

#define mp make_pair
#define sz(x) ((int)((x).size()))

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair < int , int > ipair;
typedef pair < ll , ll > lpair;
const int IINF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const double DINF = numeric_limits<double>::infinity();
const ll MOD = 1000000007;
const ld EPS = 1e-9;
const int DX[] = { 1,  0, -1,  0,  1, -1,  1, -1};
const int DY[] = { 0,  1,  0, -1,  1, -1, -1,  1};

// ========================================================================= //

const int N = 150179;

struct Task
{
    ll p, t;
};

int n;
Task a[N];
ld ans = 1.0;
map < int , lpair > w;

int main()
{
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i].p;
    for (int i = 0; i < n; ++i)
        cin >> a[i].t;
    sort(a, a + n, [](const Task & x, const Task & y)
    {
        ll v1 = x.t*y.p;
        ll v2 = y.t*x.p;
        return v1 < v2;
    });

    int sp = 0;
    ll tsum = 0;
    for (int i = 1; i <= n; ++i)
        if (i == n || a[i-1].t*a[i].p != a[i-1].p*a[i].t)
        {
            int ep = i;
            ll ctsum = 0;
            for (int j = sp; j < ep; ++j)
                ctsum += a[j].t;
            for (int j = sp; j < ep; ++j)
            {
                if (w.count(a[j].p) == 0)
                    w[a[j].p] = lpair(tsum + a[j].t, tsum + ctsum);
                else
                {
                    auto & cw = w[a[j].p];
                    cw.first = min(cw.first, tsum + a[j].t);
                    cw.second = max(cw.second, tsum + ctsum);
                }
            }
            tsum += ctsum;
            sp = ep;
        }

    vector < pair < int , lpair > > wv(w.begin(), w.end());
    for (int i = 1; i < sz(wv); ++i)
    {
        ld nans = ld(wv[i].first - wv[i-1].first) / (wv[i].first*wv[i].second.second - wv[i-1].first*wv[i-1].second.first) * tsum;
        if (nans > -EPS)
            ans = min(ans, nans);
    }

    cout.precision(40);
    cout << max(ans, ld(0.0)) << "\n";

    return 0;
}