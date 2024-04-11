/*
    Soheil Mohammadkhani
    i'm sad :(
    aghayi ke dari in code ro mikhooi, in kod copyie :|
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

ll n, k;
ll C[MAXN], M[MAXN], cnt[MAXN];
multiset<ll> st;
vector<ll> res[MAXN];

int main() {
    cin >> n >> k;
    for (ll i = 0; i < n; i++) cin >> M[i], st.insert(k - M[i]);

    for (int i = 0; i < k; i++) cin >> C[i];
    reverse(C, C + k);
    ll ans = 0;
    while (SZ(st)) {
        ans++;
        ll cnt = 0;
        while (true) {
            cnt++;
            ll ind = lower_bound(C, C + k, cnt) - C;
            auto it = st.lower_bound(ind);
            if (it == st.end()) break;
            res[ans].push_back(k - *it);
            st.erase(it);
        }
    }

    cout << ans << endl;
    for (int i = 1; i <= ans; i++) {
        cout << SZ(res[i]) << sep;
        for (int j : res[i]) cout << j << sep;
        cout << endl;
    }
    fast_io;
    return 0;
}