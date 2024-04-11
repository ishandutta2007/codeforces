/*
    Soheil Mohammadkhani
    I will change this text here when i've got "Candidate Master":)
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define SZ(x)                       ll(x.size())
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll A[MAXN], B[MAXN];

ll solve() {
    ll n;
    cin >> n;
    map<pll, ll> mp;
    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < n; i++) cin >> B[i];

    if (!is_permutation(A, A + n, B, B + n)) return cout << "NO" << endl, 0;

    for (int i = 0; i < ceil(n / ld(2)); i++) {
        ll x = A[i], y = A[n - i - 1];
        if (x > y) swap(x, y);
        if (mp.find({x, y}) == mp.end()) mp.insert({{x, y}, 0});
        mp[{x, y}]++;
    }

    for (int i = 0; i < ceil(n / ld(2)); i++) {
        ll x = B[i], y = B[n - i - 1];
        if (x > y) swap(x, y);
        if (mp.find({x, y}) == mp.end()) return cout << "NO" << endl, 0;
        mp[{x, y}]--;
    }

    for (pair<pll, ll> p : mp) if (p.Y != 0) return cout << "NO" << endl, 0;

    cout << "YES" << endl;
    return 0;
}

int main() {
    fast_io;
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}