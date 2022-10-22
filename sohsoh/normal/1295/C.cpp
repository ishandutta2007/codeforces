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

const ll MAXN = 1e5 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll fi[MAXN][26] = {0};

ll solve() {
    string s, t;
    cin >> s >> t;
    reverse(all(s));
    ll n = SZ(s);
    for (int i = 0; i < 26; i++) {
        ll now = -1;
        ll ind = n - 1;
        for (char c : s) {
            if (c - 'a' == i) {
                now = ind;
            }

            fi[ind][i] = now;
            ind--;
        }
    }

    reverse(all(s));
    ll ans = 1;
    ll now_ind = 0;
    for (char c : t) {
        if (fi[0][c - 'a'] == -1) return cout << -1 << endl, 0;
        if (fi[now_ind][c - 'a'] > -1 && now_ind < n) {
            now_ind = fi[now_ind][c - 'a'] + 1;
        } else {
            ans++;
            now_ind = fi[0][c - 'a'] + 1;
        }
    }

    cout << ans << endl;
}

int main() {
    fast_io;
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}