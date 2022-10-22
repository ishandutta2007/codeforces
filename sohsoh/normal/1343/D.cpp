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

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll p(int i, ll n) {
    return n - i - 1;
}

ll sum[MAXN];
ll mx[MAXN];
ll mi[MAXN];

int solve() {
    ll n, k;
    cin >> n >> k;

    ll* a = new ll[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    fill(sum, sum + 2 * k + 100, 0);
    fill(mi, mi + 2 * k + 100, 0);
    fill(mx, mx + 2 * k + 100, 0);

    ll d = 0;
    for (int i = 0; i < n; i++) {
        ll x, y;
        x = a[i];
        y = a[p(i, n)];

        if (x <= k && y <= k)
            sum[x + y]++;
        if (x <= k && y <= k) {
            mi[min(x, y) + 1]++;
            mx[max(x, y) + k]++;
        } else if (x <= k || y <= k) {
            mi[min(x, y) + 1]++;
            mx[min(x, y) + k]++;
        } else {
            d++;
        }
    }

    for (int i = 1; i <= 2 * k; i++) {
        mx[i] = mx[i - 1] + mx[i];
    }

    for (int i = 2 * k - 1; i >= 0; i--) {
        mi[i] = mi[i + 1] + mi[i];
    }

    ll minn = INF;
    for (int i = 1; i <= 2 * k; i++) {
        ll fail = mi[i + 1] + mx[i - 1] + d;
        ll res = fail * 2 + n - sum[i] - fail;
        minn = min(res, minn);
    }

    cout << minn / 2 << endl;
    return 0;
}

int main() {
    fast_io;
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}