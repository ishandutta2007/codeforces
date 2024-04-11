#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = (int)3005;
const ll INF = (ll)1e18;

int n, k;
vector<ll> arr[N];
ll dp[N][N];
ll res = 0;

void solve(int l, int r, int off) {
    if(l == r) {
        for(int i = 1; i <= sz(arr[l]); i++) {
            res = max(res, dp[off][k - i] + arr[l][i - 1]);
        }
        return ;
    }

    function<int(int, int)> update = [&](int tl, int tr) {
        int nxtoff = off;
        for(int j = tl; j <= tr; j++) {
            nxtoff++;
            for(int i = 0; i <= k; i++) {
                dp[nxtoff][i] = dp[nxtoff - 1][i];
                if(i >= sz(arr[j])) dp[nxtoff][i] = max(dp[nxtoff][i], dp[nxtoff - 1][i - sz(arr[j])] + arr[j].back());
            }
        }
        return nxtoff;
    };
    int mid = (l + r) / 2;
    solve(l, mid, update(mid + 1, r));
    solve(mid + 1, r, update(l, mid));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    dp[0][0] = 0;
    fill(dp[0] + 1, dp[0] + N, -INF);

    rep(i, 0, n) {
        int s; cin >> s;
        for(int j = 0; j < s; j++) {
            int x; cin >> x;
            if(j < k) arr[i].push_back(x + (arr[i].empty() ? 0 : arr[i].back()));
        }
    }
    solve(0, n - 1, 0);
    cout << res << '\n';
}