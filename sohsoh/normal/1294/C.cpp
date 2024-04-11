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
#define bug(x)                      cerr << #x << ": " <<  x <<  " ";
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define FOR(n)                      for (int i = 0; i < n; i++)
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll poww(ll a, ll b, ll md) {
    if (b == -1) return poww(a, md - 2, md);
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 250000 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll NMAX = 1e6 + 10;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

bool is_prime(ll n) {
    ll sq = sqrt(n);
    if (n == 1) return false;
    for (int i = 2; i <= sq; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

ll solve() {
    ll n;
    cin >> n;
    ll sq = sqrt(n);

    ll c = 0;
    ll a[2] = {0};
    for (int i = 2; i <= sq; i++) {
//        cout << i << endl;
        if (n % i > 0) continue;
        ll x = n / i;
        if (is_prime(i)) {
            n /= i;
            a[c] = i;
            c++;
        }

        if (c > 1) break;

        if (is_prime(i) && n % (i * i) == 0) {
            a[1] = i * i;
            n /= i * i;
            c++;
            break;
        }
//
//        cout << n << endl;

        if (x > 1 && is_prime(x) && x != i && c < 2) {
            n /= x;
            a[c] = x;
            c++;
        }

        if (c > 1) break;
    }

//    cout << n << endl;

    if (n == 1 || c < 2 || a[0] == n || a[1] == n) return cout << "NO" << endl, 0;
    cout << "YES" << endl << a[0] << sep << a[1] << sep << n << endl;
    return 0;
}

int main() {
    fast_io;
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}