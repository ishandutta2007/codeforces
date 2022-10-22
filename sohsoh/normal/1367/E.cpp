/*
    Soheil Mohammadkhani
    div 3 contest :)
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

const ll MAXN = 1e6 + 10; //Change this bullshit :| to prevent all of the runtimes :|
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll C[MAXN], CC[MAXN];
ll n, k;

bool calc(ll len, ll x) {
    for (int i = 0; i < 26; i++) CC[i] = C[i];
    ll need = len / x;
    ll ind = 0;
    for (int i = 0; i < x; i++) {
        if (CC[ind] < need) {
            ind++;
            i--;
            if (ind >= 26) return false;
            continue;
        }

        CC[ind] -= need;
    }

    return true;
}

ll solve() {
    fill(C, C + 26, 0);
    cin >> n >> k;
    vector<ll> v;
    string s;
    cin >> s;
    for (char c : s) C[c - 'a']++;
    sort(C, C + 26);
    reverse(C, C + 26);
    for (int i = 1; i <= k; i++) if (k % i == 0) v.push_back(i);
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        bool can = false;
        for (ll x : v) {
            if (i % x == 0 && calc(i, x)) {
                can = true;
                break;
            }
        }

        if (can) ans = i;
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