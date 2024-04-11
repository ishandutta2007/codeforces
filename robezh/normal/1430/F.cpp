#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = 2005;
const ll INF = (ll)1e18;

int n, k;
int l[N], r[N], a[N];
ll cost[N][N], scost[N];
ll dp[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    rep(i, 1, n + 1) cin >> l[i] >> r[i] >> a[i];
    for(int i = 0; i < N; i++) fill(cost[i], cost[i] + N, INF);
    fill(scost, scost + N, INF);
    for(int i = 1; i <= n; i++) {
        ll curk = k;
        ll cnt = 0;
        bool bad = false;
        for(int j = i; j <= n; j++) {
            if(curk < a[j]) {

                ll charge = (a[j] - curk + k - 1) / k;
                cnt += charge;
                if(charge > r[j] - l[j]) {
                    bad = true;
                    break;
                }
                curk = curk + charge * k - a[j];
                if(j + 1 <= n && l[j + 1] - l[j] > charge) {
                    cost[i][j] = cnt + 1;
                }
            } else {
                curk -= a[j];
                if(j + 1 <= n && l[j + 1] - l[j] > 0) {
                    cost[i][j] = cnt + 1;
                }
            }
        }
        if(!bad) {
            scost[i] = cnt * k - curk;
        }
    }
    fill(dp, dp + N, INF);
    dp[0] = 0;
    ll res = INF;
    for(int i = 1; i < n; i++) {
        for(int la = 0; la < i; la++) {
            dp[i] = min(dp[i], dp[la] + cost[la + 1][i]);
        }
        if(dp[i] == INF) continue;
//        cout << i << ": " << dp[i] << ",   " << scost[i + 1] << endl;
        res = min(res, dp[i] * k + scost[i + 1]);
    }

//    cout << cost[1][1] << endl;
    ll fres = k + min(res, scost[1]);
    if(fres > INF / 2) fres = -1;
    cout << fres << '\n';

}