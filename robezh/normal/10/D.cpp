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
const int N = 505;

int n, m;
int a[N], b[N];
int dp[N];
int pre[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    rep(i, 1, n + 1) cin >> a[i];
    cin >> m;
    rep(i, 1, m + 1) cin >> b[i];
    rep(i, 1, n + 1) {
        int k = 0;
        rep(j, 1, m + 1) {
            if(a[i] == b[j] && dp[j] < dp[k] + 1) {
                dp[j] = dp[k] + 1;
                pre[j] = k;
            } else if(b[j] < a[i]) {
                if(dp[j] > dp[k]) k = j;
            }
        }
    }
    int loc = 0;
    rep(i, 1, m + 1) if(dp[i] > dp[loc]) loc = i;
    cout << dp[loc] << '\n';
    vi rs;
    while(loc) rs.push_back(b[loc]), loc = pre[loc];
    reverse(all(rs));
    for (int x : rs) cout << x << " ";
    cout << endl;
}