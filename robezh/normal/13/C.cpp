#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
const int N = 5005;
const ll INF = (ll)1e18;

int n;
int num[N];
P p[N];
//int rk[N];
ll dp[2][N];

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> num[i];
        p[i].first = num[i], p[i].second = i;
    }
    sort(p + 1, p + n + 1);
//    for(int i = 1; i <= n; i++) rk[p[i].second] = i;

    int la = 0, nw = 1;
    fill(dp[nw] + 1, dp[nw] + n + 1, 0);
    for(int i = 1; i <= n; i++) {
        swap(la, nw);
        fill(dp[nw] + 1, dp[nw] + n + 1, INF);
        int cur_num = num[i];
        ll pmin = INF;
        for(int j = 1; j <= n; j++) {
            pmin = min(pmin, dp[la][j]);
            dp[nw][j] = pmin + abs(cur_num - p[j].first);
        }
    }
    ll res = INF;
    for(int i = 1; i <= n; i++) res = min(res, dp[nw][i]);
    cout << res << endl;
};