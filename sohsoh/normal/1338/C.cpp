/*
    Soheil Mohammadkhani
    if you are reading this you are reading this   --Javad Khiabani-- :)
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

int solve() {
    ll n;
    cin >> n;

    ll mod3 = n % 3;
    if (mod3 == 0) n = n / 3;
    else n = n / 3 + 1;

    ll tmp_n = n;
    ll p = 1;
    ll k = 0;
    while (n > 0)  {
        n -= p;
        k++;
        p *= 4;
    }

    n += p / 4;

    bitset<62> a;
    bitset<62> b;
    bitset<62> c;

    n--;

    int j = 0;
    k--;
    while (k > 0) {
        if (n % 4 == 0) {
            a[2 * j] = 0; a[2 * j + 1] = 0;
            b[2 * j] = 0; b[2 * j + 1] = 0;
            c[2 * j] = 0; c[2 * j + 1] = 0;
        } else if (n % 4 == 1) {
            a[2 * j] = 1; a[2 * j + 1] = 0;
            b[2 * j] = 0; b[2 * j + 1] = 1;
            c[2 * j] = 1; c[2 * j + 1] = 1;
        } else if (n % 4 == 2) {
            a[2 * j] = 0; a[2 * j + 1] = 1;
            b[2 * j] = 1; b[2 * j + 1] = 1;
            c[2 * j] = 1; c[2 * j + 1] = 0;
        } else if (n % 4 == 3) {
            a[2 * j] = 1; a[2 * j + 1] = 1;
            b[2 * j] = 1; b[2 * j + 1] = 0;
            c[2 * j] = 0; c[2 * j + 1] = 1;
        }
        n /= 4;
        j++;
        k--;
    }

    a[2 * j + 1] = 0; a[2 * j] = 1;
    b[2 * j + 1] = 1; b[2 * j] = 0;
    c[2 * j + 1] = 1; c[2 * j] = 1;

    if (mod3 == 0) cout << c.to_ullong() << endl;
    else if (mod3 == 1) cout << a.to_ullong() << endl;
    else cout << b.to_ullong() << endl;
//
//    cout << j << endl;
//    cout << n << endl;
//    cout << endl;
    return 0;
}

int main() {
    fast_io;
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}