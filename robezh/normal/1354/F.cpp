#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
//typedef pair<int, int> pii;
typedef vector<int> vi;

struct pii {
    int first, second, id;
};

const int N = 76, INF = (int)1e9;
int n, k;
pii p[N];

int dp[N][N], tk[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n >> k;
        rep(i, 1, n + 1) cin >> p[i].first >> p[i].second, p[i].id = i;
        sort(p + 1, p + n + 1, [](const pii &p1, const pii &p2) {
            return p1.second < p2.second;
        });
        rep(i, 0, n + 1) fill(dp[i], dp[i] + n + 1, -INF);
        dp[0][0] = 0;
        for(int i = 1; i <= n; i++) {
//            cout << p[i].id << endl;
            for(int j = 0; j <= k; j++) {
                if(j >= 1) {
                    int take_dp = dp[i - 1][j - 1] + (j - 1) * p[i].second + p[i].first;
                    if(take_dp > dp[i][j]) {
                        dp[i][j] = take_dp;
                        tk[i][j] = 1;
                    }
                }
                int not_dp = dp[i - 1][j] + (k - 1) * p[i].second;
                if(not_dp > dp[i][j]) {
                    dp[i][j] = not_dp;
                    tk[i][j] = 0;
                }
            }
        }
        vi take, not_take;
//        cout << dp[n][k] << endl;
        int cur = k;
        for(int i = n; i >= 1; i--) {
            (tk[i][cur] ? take : not_take).push_back(p[i].id);
            cur -= tk[i][cur];
        }
        reverse(all(take));
        cout << take.size() + not_take.size() * 2 << '\n';

        for(int i = 0; i < k - 1; i++) cout << take[i] << " ";
        for(auto x : not_take) cout << x << " " << -x << " ";
        cout << take[k - 1] << '\n';
    }

}