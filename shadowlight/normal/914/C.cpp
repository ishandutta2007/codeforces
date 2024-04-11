#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1007;
const double EPS = 1e-8;

int calc(int x) {
    int res = 0;
    while (x) {
        if (x % 2) {
            res++;
        }
        x /= 2;
    }
    return res;
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
    string s;
    cin >> s;
    int all = 0;
    while (s.size() && s.back() == '1') {
        s.pop_back();
        all++;
    }
    if (s.size()) {
        s.pop_back();
    }
    s += "1";
    for (int i = 0; i < all; i++) {
        s += "0";
    }
    int k;
    cin >> k;
    vector <int> d(MAXN, 0);
    for (int i = 2; i < MAXN; i++) {
        d[i] = d[calc(i)] + 1;
    }
    vector <int> dp(MAXN, 0);
    int cnt = 0;
    for (int i = 0; i < (int) s.size(); i++) {
        vector <int> ndp(MAXN, 0);
        for (int j = 0; j < MAXN - 1; j++) {
            ndp[j] += dp[j];
            if (ndp[j] >= INF) {
                ndp[j] -= INF;
            }
            ndp[j + 1] += dp[j];
            if (ndp[j + 1] >= INF) {
                ndp[j + 1] -= INF;
            }
        }
        int x = s[i] - '0';
        if (x) {
            ndp[cnt]++;
            if (ndp[cnt] >= INF) {
                ndp[cnt] -= INF;
            }
            cnt++;
        }
        dp = ndp;
    }
    int res = 0;
    for (int i = 2; i < MAXN; i++) {
        if (d[i] + 1 != k) continue;
        res += dp[i];
        if (res >= INF) {
            res -= INF;
        }
    }
    if (!k) {
        res = 1;
    } else if (d[1] + 1 == k) {
        res += dp[1] - 1;
        if (res >= INF) {
            res -= INF;
        }
    }
    cout << res;
}