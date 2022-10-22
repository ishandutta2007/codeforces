/*
    Soheil Mohammadkhani
    bullshit candidate master :|
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
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll cnt[10];

ll solve() {
    string s;
    cin >> s;
    fill(cnt, cnt + 10, 0);
    for (char c : s) {
        cnt[c - '0']++;
    }

    ll ans = INF;
    ans = min(ans, ll(s.size() - *max_element(cnt, cnt + 10)));

    for (char i = '0'; i <= '9'; i++) {
        for (char j = '0'; j <= '9'; j++) {
            if (i == j) continue;
            bool b = true;
            ll tans = 0;
            for (char c : s) {
                if (b) {
                    if (c == i) b = !b;
                    else tans++;
                } else {
                    if (c == j) b = !b;
                    else tans++;
                }
            }

            if ((ll(s.size()) - tans) & 1) tans++;
            ans = min(ans, tans);
        }
    }

    cout << ans << endl;
    return 0;
}

int main() {
    fast_io;
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}