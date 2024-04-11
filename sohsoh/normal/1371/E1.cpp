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

const ll MAXN = 1e5 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n, p, M[MAXN] = {0};

ll solve(ll x) {
    ll ans = 1;
    for (int i = 0; i < n; i++) {
        ans *= (M[x] - i);
        ans %= p;
        x++;
    }

    return ans;
}

int main() {
    fast_io;
    cin >> n >> p;
    ll mx = 0;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        M[x]++;
        mx = max(mx, x);
    }

    vector<ll> ans;
    for (int i = 1; i < MAXN; i++) M[i] += M[i - 1];
    for (int i = 1; i <= mx; i++) {
        if (solve(i) % p > 0) {
            ans.push_back(i);
        }
    }

    cout << ans.size() << endl;
    for (ll e : ans) cout << e << sep;
    cout << endl;
    return 0;
}