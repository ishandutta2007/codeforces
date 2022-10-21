#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
const ll INF = (ll)1e18;
const int N = (int)3e5 + 50;

int n, q;
int a[N];
ll dp[N][2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n >> q;
        rep(i, 1, n + 1) cin >> a[i];
        dp[0][0] = -INF;
        dp[0][1] = 0;
        rep(i, 1, n + 1) {
            dp[0][0] = max(dp[0][0], dp[0][1] + a[i]);
            dp[0][1] = max(dp[0][1], dp[0][0] - a[i]);
        }
        
        cout << max(dp[0][0], dp[0][1]) << '\n';
    }

}