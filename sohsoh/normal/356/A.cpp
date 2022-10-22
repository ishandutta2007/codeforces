/*
	:)
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

const ll MAXN = 1e6 + 100;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n, m, ans[MAXN] = {0};
set<ll> st;

int main() {
    fast_io;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) st.insert(i);
    for (int i = 0; i < m; i++) {
        ll l, r, x;
        cin >> l >> r >> x;
        auto it = st.lower_bound(l);
        while (it != st.end() && *it <= r) {
            if (*it == x) {
                it++;
                continue;
            }
            ans[*it] = x;
            it = st.erase(it);
        }
    }

    for (int i = 1; i <= n; i++) cout << ans[i] << sep;
    cout << endl;
    return 0;
}