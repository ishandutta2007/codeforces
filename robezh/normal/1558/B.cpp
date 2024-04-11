#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int N = (int)4e6 + 50;

int n, mod;
ll dp[N], add[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    dp[1] = 1;
    cin >> n >> mod;
    ll csum = 0;
    for (int i = 1; i <= n; i++) {
        csum = (csum + add[i]) % mod;
        ll cdp = (i == 1 ? 1 : dp[i - 1] + csum) % mod;
//        cout << i << " " << add[i] << " " << cdp << endl;
        for (int j = i * 2; j < N; j += i) {
            add[j] = (add[j] + cdp) % mod;
            if(j + j / i < N) add[j + j / i ] = (add[j + j / i ] - cdp) % mod;
        }
        dp[i] = (cdp + dp[i - 1]) % mod;
//        cout << i << " " << dp[i] << endl;
    }
    cout << ((dp[n] - dp[n - 1]) % mod + mod) % mod << '\n';




}