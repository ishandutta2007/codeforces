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

ll A[MAXN];
set<pll> st;

ll solve() {
    ll n;
    cin >> n;
    ll ans = 0;
    A[0] = 0;
    for (int i = 1; i <= n; i++) {
        ll x;
        cin >> x;
        if (x == 2) x = -1;
        A[n - i + 1] = x;
        ans += x;
    }

    st.insert({0, 0});
    ll w = 0;
    for (int i = 1; i <= n; i++) {
        ll x;
        cin >> x;
        if (x == 2) x = -1;
        w += x;
        ans += x;
        st.insert({w, i});
    }

    ll f_ans = INF;
    for (int i = 0; i <= n; i++) {
        ans -= A[i];
        if (st.lower_bound({ans, 0}) == st.end() || st.lower_bound({ans, 0}) -> X != ans) continue;
        ll x = st.lower_bound({ans, 0}) -> Y;
//        debug(ans);
//        debug(i)
//        debug(x);
        f_ans = min(f_ans, i + x);
    }

    st.clear();
    cout << f_ans << endl;
    return 0;
}

int main() {
    fast_io;
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}