#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define subnb true
#define Lnb true
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int N = (int)1e6 + 50, mod = 998244353;

int dvs[N];
int n, dp[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    rep(i, 1, N) {
        for (int j = i; j < N; j += i) dvs[j]++;
    }

    cin >> n;
    dp[1] = 1;
    rep(i, 2, n + 1) {
        dp[i] = (2 * dp[i - 1] + dvs[i]) % mod;
    }
    cout << (dp[n] + mod - dp[n - 1]) % mod << endl;


}