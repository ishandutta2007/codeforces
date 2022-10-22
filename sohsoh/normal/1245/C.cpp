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

pll dp[MAXN];

int main() {
    fast_io;
    dp[0] = {0, 1};
    dp[1] = {0, 1};
    for (int i = 2; i < MAXN; i++) dp[i] = {dp[i - 1].Y % MOD, (dp[i - 1].X + dp[i - 1].Y) % MOD};
    string s;
    cin >> s;
    ll n = 0, u = 0, ans = 1;
    for (char c : s) {
        if (c == 'w' || c == 'm') return cout << 0 << endl, 0;
        if (c == 'n') {
            ans *= dp[u].X + dp[u].Y;
            ans %= MOD;
            u = 0;
            n++;
        } else if (c == 'u') {
            ans *= dp[n].X + dp[n].Y;
            ans %= MOD;
            n = 0;
            u++;
        } else {
            ans *= dp[n].X + dp[n].Y;
            ans %= MOD;
            ans *= dp[u].X + dp[u].Y;
            ans %= MOD;
            u = 0;
            n = 0;
        }
    }


    ans *= dp[n].X + dp[n].Y;
    ans *= dp[u].X + dp[u].Y;

    cout << ans % MOD << endl;
    return 0;
}