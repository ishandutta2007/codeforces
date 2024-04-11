/*
	STO
*/
#pragma optimize("g", on)
#pragma optimize("s", on)
#pragma optimize("y", on)
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

set<pll> st1, st2;
ll here[MAXN];
bool B[MAXN];

int main() {
    fast_io;
    string s;
    cin >> s;
    ll ps = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') ps++, B[i] = true;
        else ps--, B[i] = false;
        here[i] = ps;
        st1.insert({ps, i});
        st2.insert({ps, -1 * i});
    }

    ll mx = 0, cnt = 0;
    ll x = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s.size() - i + 1 < mx) continue;
        auto f = st1.lower_bound({x - 1, -1 * INF});
        ll e = s.size() - 1;
        if (f != st1.end() && f -> X == x - 1) e = f -> Y;
        auto f2 = st2.lower_bound({x, -1 * e});
        if (f2 != st2.end() && (f2 -> X == x)) {
            e = -1 * (f2 -> Y);
            if (e + 1 - i > mx) {
                mx = e + 1 - i;
                cnt = 0;
            }

            if (e + 1 - i == mx) cnt++;
        }

        if (B[i]) x++;
        else x--;

        ll y = here[i];
        st1.erase({y, i});
        st2.erase({y, -1 * i});
    }

    if (mx) cout << mx << sep << cnt << endl;
    else cout << 0 << sep << 1 << endl;
    return 0;
}