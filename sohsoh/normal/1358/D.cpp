/*
    Soheil Mohammadkhani
    I will change this text here when i've got "Expert" :)
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

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

const ll MAXN = 2e5 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n, x;
ll pref[MAXN * 2] = {0}, ps[MAXN * 2] = {0}, a[MAXN];

int main() {
    fast_io;
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i < 2 * MAXN; i++) {
        pref[i] = pref[i - 1];
        ps[i] = ps[i - 1];
        pref[i] += a[(i - 1) % n];
        ps[i] += a[(i - 1) % n] * (a[(i - 1) % n] + 1) / 2;
    }

    ll bf = 0;
    for (int i = 0; i < n; i++) {
        ll ind = lower_bound(pref, pref + 2 * MAXN, pref[i] + x) - pref;
        ll ans = ps[ind] - ps[i];
        ll y = pref[ind] - pref[i] - x;
        ans -= y * (y + 1) / 2ll;
        bf = max(bf, ans);
    }

    cout << bf << endl;

    return 0;
}