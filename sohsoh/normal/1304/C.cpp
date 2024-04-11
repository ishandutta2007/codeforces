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

bool used[MAXN] = {false};

int solve() {
    ll n, m;
    cin >> n >> m;

    bool b = false;

    ll prev_time = 0;
    ll prev_max = m, prev_min = m;
    for (int i = 0; i < n; i++) {
        ll t, l, h;
        cin >> t >> l >> h;
        //TODO TAHT
        ll time = t - prev_time;
        prev_min -= time;
        prev_max += time;
        prev_time = t;

        if (h < prev_min || l > prev_max) {
            b = true;
        }


//        bug(time)
//        bug(prev_min)
//        debug(prev_max);

        if (l > prev_min) {
            prev_min = l;
        }

        if (h < prev_max) {
            prev_max = h;
        }


//        bug(prev_min)
//        debug(prev_max);
    }

    if (b) return cout << "NO" << endl, 0;
    cout << "YES" << endl;
    return 0;
}

int main() {
    fast_io;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}