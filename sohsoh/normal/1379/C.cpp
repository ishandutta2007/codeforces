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
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const ll MAXN = 2e5 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 6; // 998244353; // 1e9 + 9;

pll A[MAXN];
ll ps[MAXN];

ll solve() {
    ll n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) cin >> A[i].X >> A[i].Y;
    sort(A, A + m);
    reverse(A, A + m);
    ps[0] = A[0].X;
    for (int i = 1; i < m; i++) ps[i] = ps[i - 1] + A[i].X;
    ll ans = 0;
    if (n <= m) ans = ps[n - 1];
    for (int i = 0; i < m; i++) {
        ll tans = 0;
        ll L = 0, R = min(n, m) - 1;
        while (L < R) {
            ll mid = (L + R + 1) / 2;
            if (A[mid].X >= A[i].Y) L = mid;
            else R = mid - 1;
        }

        tans += ps[L];
        ll r = n - L - 1;
        if (A[i].X < A[i].Y) tans += A[i].X, r--;
        if (r < 0) {
            continue;
        }

        tans += r * A[i].Y;
        ans = max(ans, tans);
        ans = max(ans, A[i].X + (n - 1) * A[i].Y);
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