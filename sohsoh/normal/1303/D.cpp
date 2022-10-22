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
const ll LOG = 100;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll solve() {
    ll n, m;
    cin >> n >> m;
    ll seed[LOG] = {0};
    bitset<LOG> b(n);
    ll s = 0;
    for (int i = 0; i < m; i++) {
        ll k;
        cin >> k;
        seed[int(log2(k))]++;
        s += k;
    }

    if (s < n) {
        return cout << -1 << endl, 0;
    }

    for (int i = 0; i < LOG; i++) {
        if (b[i] == 0) continue;
        // b[i] == 1
        if (b[i] && seed[i] > 0) {
            seed[i]--;
            b[i] = 0;
        }
    }

    if (b.to_ullong() == 0) return cout << 0 << endl, 0;

    ll div = 0;
    for (int i = 0; i < LOG - 1; i++) {
        if (b[i] && seed[i] > 0) {
            seed[i]--;
            b[i] = 0;
        } else if (b[i]) {
            for (int j = i + 1; j < LOG; j++) {
                if (seed[j] - int(b[j]) > 0) {
                    seed[j]--;
                    ll diff = j - i;
                    div += diff;
                    for (int k = j - 1; k >= i; k--) seed[k]++;
//                    cout << j << endl;
                    break;
                }
            }

            seed[i]--;
            b[i] = 0;
        }

        seed[i + 1] += seed[i] / 2;
    }

    cout << div << endl, 0;
}

int main() {
    fast_io;
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}