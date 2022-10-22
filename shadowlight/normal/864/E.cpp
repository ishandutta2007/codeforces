#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 2007;
const double EPS = 1e-8;

struct Data {
    int t, d, p;
    int id;
};

bool operator<(Data a, Data b) {
    return a.d < b.d;
}

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    int n;
    cin >> n;
    vector <Data> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].t >> a[i].d >> a[i].p;
        a[i].id = i + 1;
    }
    sort(a.begin(), a.end());
    vector <vector <int> > dp(n + 1, vector <int> (MAXN, 0));
    vector <vector <bool> > need(n + 1, vector <bool> (MAXN, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < MAXN; j++) {
            if (dp[i + 1][j] < dp[i][j]) {
                dp[i + 1][j] = dp[i][j];
                need[i + 1][j] = false;
            }
            if (a[i].d > j + a[i].t) {
                if (dp[i + 1][j + a[i].t] < dp[i][j] + a[i].p) {
                    dp[i + 1][j + a[i].t] = dp[i][j] + a[i].p;
                    need[i + 1][j + a[i].t] = true;
                }
            }
        }
    }
    int res = 0;
    int pos = -1;
    for (int i = 0; i < MAXN; i++) {
        if (dp[n][i] > res) {
            res = dp[n][i];
            pos = i;
        }
    }
    cout << res << "\n";
    if (!res) {
        cout << 0;
        return 0;
    }
    vector <int> ans;
    int tm = pos;
    for (int i = n; i > 0; i--) {
        if (need[i][tm]) {
            ans.push_back(a[i - 1].id);
            tm -= a[i - 1].t;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (int x : ans) {
        cout << x << " ";
    }
}