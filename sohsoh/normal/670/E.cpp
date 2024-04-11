/*
	wtf
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> plll;

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

ll n, m, p, s = 0;
list<pair<bool, ll>> v;

int main() {
    cin >> n >> m >> p;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        if (c == '(') {
            s++;
            v.push_back({true, s});
        } else {
            v.push_back({false, s});
            s--;
        }
    }

    auto it = v.begin();
    p--;
    while (p--) it++;
    for (int i = 0; i < m; i++) {
        char c;
        cin >> c;
        if (c == 'L' && it != v.begin()) it--;
        if (c == 'R' && it != v.end()) {
            it++;
            if (it == v.end()) it--;
        }

        if (c == 'D') {
            ll t = it -> Y;
            if (it -> X) {
                ll x = 0;
                while (x < 2) {
                    if (it -> Y == t) x++;
                    it = v.erase(it);
                }
            } else {
                ll x = 0;
                while (x < 2) {
                    if (it -> Y == t) x++;
                    it = v.erase(it);
                    it--;
                }

                it++;
            }

            if (it == v.end()) it--;
        }
    }

    for (pair<bool, ll> p : v) {
        if (p.X) cout << '(';
        else cout << ')';
    }

    cout << endl;
    return 0;
}