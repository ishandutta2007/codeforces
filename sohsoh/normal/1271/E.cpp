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
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 5000 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n, k, odd_ans;

ll calc(ll x) {
    if (x == 1 || x == 0) return n;

    ll p = 1;
    if (x % 2 == 0) p = 2;

    ll ans = 0;
    while (x + p - 1 <= n) {
        ans += p;
        p *= 2;
        x *= 2;
    }

    if (n - x + 1 > 0) ans += n - x + 1;
    return ans;
}

int main() {
    fast_io;
    cin >> n >> k;

    ll l = 1, h = n;
    if (h % 2 == 0) h--;
    while (l < h) {
        ll mid = (l + h) / 2;
        if (mid % 2 == 0) mid++;
        if (calc(mid) < k) h = mid - 2;
        else l = mid;
    }
    odd_ans = h;

    l = 0, h = n;
    if (h % 2 == 1) h--;
    while (l < h) {
        ll mid = (l + h) / 2;
        if (mid % 2 == 1) mid++;
        if (calc(mid) < k) h = mid - 2;
        else l = mid;
    }
    cout << max(odd_ans, h) << endl;
    return 0;
}