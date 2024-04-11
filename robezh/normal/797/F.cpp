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

const int N = 5005;
const ll INF = (ll)1e18;

int n, m;
int x[N];
struct P {
    int p, c;
} p[N];
ll dp[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    rep(i, 1, n + 1) cin >> x[i];
    sort(x + 1, x + n + 1);
    rep(i, 1, m + 1) cin >> p[i].p >> p[i].c;
    sort(p + 1, p + m + 1, [](const P &p1, const P &p2) {
        return p1.p < p2.p;
    });
    rep(i, 0, N) fill(dp[i], dp[i] + N, INF);

    dp[0][0] = 0;
    rep(i, 1, m + 1) {
        deque<pll> que;
        ll off = 0;
        rep(j, 0, n + 1) {
            off += abs(p[i].p - x[j]);

            ll cval = dp[i - 1][j] - off;
            while(!que.empty() && que.back().first > cval) que.pop_back();
            que.push_back({cval, j});

            while(!que.empty() && j - que.front().second > p[i].c) que.pop_front();
            dp[i][j] = que.empty() ? INF : que.front().first + off;
//            cout << i << ", " << j << ": "<< dp[i][j] << endl;
        }
    }

    ll res = (dp[m][n] >= INF ? -1 : dp[m][n]);
    cout << res << endl;
//    cout << dp[m][n] << endl;


}