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
#define debug2(x)                   cerr << #x << ": " <<  x <<  " ";
#define debug_p(x)                  cerr << #x << ": " <<  x.X <<  " " << x.Y << endl;
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define FOR(n)                      for (int i = 0; i < n; i++)
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define kill(x)                     return cout << x << endl, 0;

ll poww(ll a, ll b, ll md) {
    if (b == -1) return poww(a, md - 2, md);
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

//CHANGE IT
const ll MAXN = 8000 + 5;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll s[MAXN] = {0}, a[MAXN];

ll solve() {
    ll n;
    cin >> n;
    map<ll, ll> mp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s[i] = a[i];
        if (mp.find(a[i]) == mp.end()) mp.insert({a[i], 1});
        else mp[a[i]]++;
        if (i > 0) s[i] += s[i - 1];
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = -1; j <= i; j++) {
            if (i - j < 2) continue;
            ll c = s[i];
            if (j > -1) c -= s[j];

            auto it = mp.find(c);
            if (it == mp.end()) continue;

            ans += it -> Y;
//            debug(c);
            mp.erase(it);
        }
    }

    cout << ans << endl;

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