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

const int N = (int)1e5 + 50, INF = (int)1e9;

struct P {
    int t, x, y;
} p[N];

int r, n;
int dp[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> r >> n;
    p[0] = {0, 1, 1};
    dp[0] = 0;
    for(int i = 1; i <= n; i++) {
        cin >> p[i].t >> p[i].x >> p[i].y;
    }
    int res = -INF;
    int pmax = -INF;
    for(int i = 1; i <= n; i++) {
        dp[i] = -INF;
        int st = max(0, i - (2 * (r - 1)));
        if(st > 0) pmax = max(pmax, dp[st - 1] + 1);
        for(int la = st; la < i; la++) {
            if(abs(p[la].x - p[i].x) + abs(p[la].y - p[i].y) <= p[i].t - p[la].t) {
//                cout << la << " to " << i << endl;
                dp[i] = max(dp[i], dp[la] + 1);
            }
        }
        dp[i] = max(dp[i], pmax);
//        cout << i << " " << dp[i] << endl;
        res = max(dp[i], res);
    }
    cout << max(0, res) << '\n';

}