#include <bits/stdc++.h>
using namespace std;

#define lson(x) 2*x+1
#define rson(x) 2*x+2

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = (int)2e5 + 50;

int n, a[N], m;
vi oc[N];
int dp[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        vi xs;
        rep(i, 0, n) cin >> a[i], xs.push_back(a[i]);
        sort(all(xs));
        xs.resize(unique(all(xs)) - xs.begin());
        m = sz(xs);
        rep(i, 0, m) oc[i].clear();
        rep(i, 0, n) {
            a[i] = lower_bound(all(xs), a[i]) - xs.begin();
            oc[a[i]].push_back(i);
        }
        int res = 0;
        rep(i, 0, m) {
            res = max(res, sz(oc[i]));
            if(i + 1 < m) rep(j, 0, sz(oc[i])) {
                res = max(res, j + 1 + (int)(oc[i+1].end() - lower_bound(all(oc[i + 1]), oc[i][j])));
            }
        }
        for(int i = 0; i + 1 < m; i++) {
            dp[i] = sz(oc[i]);
            if(i > 0) {
                dp[i] += lower_bound(all(oc[i - 1]), oc[i][0]) - oc[i - 1].begin();
                if(oc[i-1].back() < oc[i][0]) dp[i] = dp[i - 1] + sz(oc[i]);
            }
            res = max(res, dp[i] + (int)(oc[i + 1].end() - lower_bound(all(oc[i + 1]), oc[i].back())));
        }
        cout << n - res << '\n';
    }
}