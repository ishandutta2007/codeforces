#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = (int)1e6 + 50;

int n;
vector<int> G[N];
int res[N], dp[N];

int solve(int up) {
    fill(dp, dp + up + 1, 0);
    for(int j = up; j >= 0; j--) {
        int mx0 = 0, mx1 = 0, cur;
        for(int nxt : G[j]) {
            if(nxt > up) continue;;
            cur = dp[nxt];
            if(cur > mx0) swap(mx0, cur);
            if(cur > mx1) mx1 = cur;
        }
        dp[j] = max(mx0, mx1 + (j != 0));
    }
    return dp[0];
}

void solve(int l, int r, int kl, int kr) {
    int tl = kl, tr = kr;
    if(l == r) {
        for(int i = tl; i <= tr; i++) res[i] = l;
        return ;
    }
    int m = (l + r) / 2, tm;
    while(tl + 1 < tr) {
        tm = (tl + tr) / 2;
        if(solve(tm) <= m) tl = tm;
        else tr = tm;
    }
    solve(l, m, kl, tl);
    solve(m + 1, r, tr, kr);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    n++;
    rep(i, 1, n) {
        int p; cin >> p; p--;
        G[p].push_back(i);
    }
//    rep(i, 1, n) cout << solve(i) << " ";
//    cout << '\n';

    int mxans = solve(n - 1);
    int la = 0;
    solve(1, mxans, 1, n - 1);
    rep(j, 1, n) cout << res[j] << " ";
    cout << '\n';
}