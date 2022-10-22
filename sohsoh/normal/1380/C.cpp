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

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll A[MAXN], dp[MAXN];

ll solve() {
    ll n, x;
    cin >> n >> x;
    for (int i = 0; i < n; i++) cin >> A[i];
    sort(A, A + n);

    for (int i = n - 1; i >= 0; i--) {
        ll s = ceil(ld(x) / A[i]);
        if (i + s > n) dp[i] = 0;
        else if (i + s == n) dp[i] = 1;
        else dp[i] = dp[i + s] + 1;
    }

    cout << *max_element(dp, dp + n) << endl;
    for (int i = 0; i < n + 10; i++) dp[i] = -1;
}

int main() {
    fast_io;
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}