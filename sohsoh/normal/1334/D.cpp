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

ll a[MAXN];
ll b[MAXN];
ll rem[MAXN];
ll cost[MAXN];

int solve() {
    ll n, r, l;
    cin >> n >> r >> l;

    ll sum = 0;
    ll prev_sum = 0;
    ll i;
    for (i = 1; i < n; i++) {
        sum += 2 * (n - i);
        if (r <= sum) {
            break;
        }

        prev_sum = sum;
    }

    r -= prev_sum;
    l -= prev_sum;
//    debug(i)
//    debug(r)
//    debug(l)

    ll k = i + 1;
    for (ll ind = 0; ind < l; ind++) {
        ll u = i;
        if (i == n) return cout << 1 << endl, 0;
        if (ind % 2 == 1) {
            u = k;
            k++;

            if (k > n) {
                i++;
                k = i + 1;
            }
        }

        if (ind >= r - 1) {
            cout << u << sep;
        }
    }

    cout << endl;
//    for (int i = 0; i < l; i++)
//    if (i == n + 1) {
//        return cout << 1 << endl, 0;
//    }
}

int main() {
    fast_io;
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}