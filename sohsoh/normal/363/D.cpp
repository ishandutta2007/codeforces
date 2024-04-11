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
#define SZ(x)                       ll(x.size())
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define debug2(x)                   cerr << #x << ": " <<  x <<  " ";
#define debug_p(x)                  cerr << #x << ": " <<  x.X <<  " " << x.Y << endl;
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define FOR(n)                      for (int i = 0; i < n; i++)
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define kill(x)                     return cout << x << endl, 0;

ll poww(ll a, ll b, ll md) {
    if (b == -1) return poww(a, md - 2, md);
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9

ll n, m, a, p[MAXN], b[MAXN], bs[MAXN] = {0}, ps[MAXN] = {0};

bool check(ll n) {
//    if (bs[n] + a - ps[n] < 0) return false;
    ll pa = a;
    for (int i = 0; i < n; i++) {
        ll c = p[n - i - 1];
        if (b[i] >= c) continue;

        ll diff = c - b[i];
        pa -= diff;
    }

    if (pa < 0) return false;

    return true;
}

int main() {
//    fast_io;
    cin >> n >> m >> a;
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < m; i++) cin >> p[i];

    sort(b, b + n);
    reverse(b, b + n);
    sort(p, p + m);

    partial_sum(b, b + n, bs + 1);
    partial_sum(p, p + m, ps + 1);

//    alog(p, m);
//    alog(ps, m);
//
    ll mn = 0, mx = min(m, n);
    while (mn != mx) {
        ll mid = (mx + mn) / 2;
        if (mx - mn == 1) {
            if (!check(mx)) mx = mn;
            else mn = mx;
            continue;
        }
        if (!check(mid)) mx = mid - 1;
        else mn = mid;
    }

    cout << mn << " " << max(ps[mn] - a, 0ll) << endl;
    return 0;
}