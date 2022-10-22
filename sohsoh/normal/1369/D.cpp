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

const ll MAXN = 2e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll cnt[MAXN] = {0}, N[MAXN] = {0}, ans[MAXN] = {0};

int main() {
    fast_io;
    N[1] = 1;
    for (int i = 2; i < MAXN; i++) {
        cnt[i] = (cnt[i - 1] + N[i - 2]) % MOD;
        N[i] = (N[i - 1] + 2 * N[i - 2]) % MOD;
        ans[i] = (ans[i - 3] + N[i - 2]) % MOD;
    }

    ll t;
    cin >> t;
    while (t--) {
        ll x;
        cin >> x;
        cout << ans[x] * 4 % MOD << endl;
    }
    return 0;
}