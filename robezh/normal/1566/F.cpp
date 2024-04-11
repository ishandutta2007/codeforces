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

const int N = (int)6e5 + 50;
const ll INF = (ll)1e18;

struct Seg{
    int l, r;
};

int n, m;
int a[N];
vector<Seg> segs[N];
ll dp[N][2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n >> m;
//        a[0] = -(int)(1e9 + 5);
        a[n + 1] = (int) (1e9 + 5);
        rep(i, 1, n + 1) cin >> a[i];
        sort(a + 1, a + n + 1);
        rep(i, 0, n + 1) segs[i].clear();
        rep(i, 1, m + 1) {
            int l, r;
            cin >> l >> r;
            int li = lower_bound(a + 1, a + n + 2, l) - a;
            int ri = lower_bound(a + 1, a + n + 2, r) - a;
            if (a[li] == l || a[ri] == r || li != ri) continue;
            segs[li - 1].push_back({l, r});
        }
//
//        rep(i, 1, n + 1) cout << a[i] << " " ;
//        cout << endl;
//
//
//
//        rep(i, 0, n + 1) {
//            cout << i << endl;
//            for (auto e : segs[i]) cout << e.l << ", " << e.r << endl;
//
////            cout << a[i] << " " ;
//        }
//        cout << endl;

        ll mx = a[n];
        for (auto p : segs[n]) mx = max(mx, (ll)p.l);
        dp[n][0] = (mx - a[n]), dp[n][1] = (mx - a[n]) * 2LL;
//        cout << dp[n][0] << " " << dp[n][1] << endl;
        for (int i = n - 1; i >= 1; i--) {
            multiset<int> S;
            sort(all(segs[i]), [](const Seg &s1, const Seg &s2) {
                return s1.l < s2.l;
            });
            for (auto &p : segs[i]) S.insert(p.r);
            dp[i][0] = dp[i][1] = INF;
            ll curmx = a[i];
            for (int j = -1; j < sz(segs[i]); j++) {
                if (j >= 0) {
                    auto &p = segs[i][j];
                    curmx = max(curmx, (ll)p.l);
                    S.erase(S.find(p.r));
                }
                ll mn = S.empty() ? a[i + 1] : *S.begin();
                dp[i][0] = min({
                                       dp[i][0],
                                       (a[i + 1] - mn) * 2LL + dp[i + 1][0] + (curmx - a[i]),
                                       (a[i + 1] - mn) + dp[i + 1][1] + (curmx - a[i]),
                               });
                dp[i][1] = min({
                                       dp[i][1],
                                       (a[i + 1] - mn) * 2LL + dp[i + 1][0] + (curmx - a[i]) * 2LL,
                                       (a[i + 1] - mn) + dp[i + 1][1] + (curmx - a[i]) * 2LL,
                               });
            }
        }
        ll res = INF;
        ll mn = a[1];
        for (auto p : segs[0]) mn = min(mn, (ll)p.r);
//        cout << mn << endl;
        res = min(dp[1][0] + 2LL * (a[1] - mn), dp[1][1] + (a[1] - mn));
        cout << res << '\n';
    }

}