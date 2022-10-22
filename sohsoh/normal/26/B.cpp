/*
	orz
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

int main() {
    fast_io;
    ll ps = 0, mn = 0;
    string s;
    cin >> s;
    ll r = 0;
    for (char c : s) {
        if (c == '(') ps++;
        else ps--;
        mn = min(mn, ps);
    }

    r += abs(mn);
    ps += abs(mn);
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == '(') r++, ps--;
        else break;
    }

    r += ps;

    cout << s.size() - r << endl;
    return 0;
}