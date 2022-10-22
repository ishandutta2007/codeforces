/*
    Soheil Mohammadkhani
    IDK :)
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define SZ(x)                       ll(x.size());
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define bug(x)                      cerr << #x << ": " <<  x <<  " ";
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define FOR(n)                      for (int i = 0; i < n; i++)
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll poww(ll a, ll b, ll md) {
    if (b == -1) return poww(a, md - 2, md);
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 3e5 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n, m;
ll mf = 0;
ll lf = INF;
ll a[MAXN][8] = {0};

ll LB = 0;

ll make_set(ll ind, ll x) {
    ll p = 1;
    ll res = 0;
    for (int i = 0; i < m; i++) {
        if (a[ind][i] >= x) {
            res += p;
        }

        p *= 2;
    }

    return res;
}

pll check_for_x(ll x) {
    vector<ll> v;
    vector<ll> vi;
    for (int i = 0; i < n; i++) {
        ll ans = make_set(i, x);
        if (find(v.begin(), v.end(), ans) == v.end()) {
            v.push_back(ans);
            vi.push_back(i);
        }
    }

    ll i = 0;
    for (ll e : v) {
        ll j = 0;
        for (ll e2 : v) {
            if ((e | e2) == LB) return {vi[i], vi[j]};
            j++;
        }
        i++;
    }

    return {-1, -1};
}

pll bin_s(ll l, ll h) {
    if (l == h) return check_for_x(l);
    ll mid = ceil(ld((h - l)) / 2) + l;
    if (check_for_x(mid).X != -1) {
        return bin_s(mid, h);
    } else {
        return bin_s(l, mid - 1);
    }
}

int main() {
    fast_io;
    cin >> n >> m;
    LB = pow(2, m) - 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            mf = max(mf, a[i][j]);
            lf = min(lf, a[i][j]);
        }
    }

    pll res = bin_s(lf, mf);
    cout << res.X + 1 << " " << res.Y + 1 << endl;

    return 0;
}