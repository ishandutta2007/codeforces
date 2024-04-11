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

int solve() {
    ll n;
    cin >> n;
    int* a = new int[n + 10];
    int* nxt = new int[n + 10];
    ll* cnt = new ll[n + 10];
    fill(cnt, cnt + n + 1, 1);

    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        a[k] = i;
        nxt[i] = i + 1;
    }

    int sure = -1;
    for (int i = 1; i <= n; i++) {
        if (sure > -1 && a[i] != sure) {
            return cout << "NO" << endl, 0;
        } else {
            cnt[a[i]] = 0;
            if (cnt[a[i] + 1] < 1 || a[i] + 1 > n) {
                sure = -1;
            } else {
                sure = a[i] + 1;
            }
        }
    }

    cout << "YES" << endl;
    return 0;
}

int main() {
    fast_io;
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}