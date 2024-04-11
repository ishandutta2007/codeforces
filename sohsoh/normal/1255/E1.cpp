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

ll n, A[MAXN], s = 0, pref[MAXN];

bool is_prime(ll x) {
    ll sq = sqrt(x);
    if (x == 1) return false;
    for (int i = 2; i <= sq; i++) if (x % i == 0) return false;
    return true;
}

ll solve(ll k) {
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll t = pref[i] % k;
        t = min(t, k - t);
        ans += t;
    }
    return ans;
}

int main() {
    fast_io;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        s += A[i];
    }

    vector<ll> poss;
    ll sq = sqrt(s);
    for (int i = 1; i <= sq; i++) {
        if (s % i) continue;
        ll n1 = i, n2 = s / i;
        if (is_prime(n1)) poss.push_back(n1);
        if (is_prime(n2)) poss.push_back(n2);
    }

    partial_sum(A, A + n, pref);

    ll ans = INF;
    for (ll e : poss) {
        ans = min(solve(e), ans);
    }

    if (ans == INF) ans = -1;
    cout << ans << endl;
    return 0;
}