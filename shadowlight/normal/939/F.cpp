#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

struct Tree {
    vector <int> t;
    int n;
    Tree(int n) : n(n), t(2 * n, 0) {}
    void build(vector <int> &a) {
        for (int i = 0; i < n; i++) {
            t[i + n] = a[i];
        }
        for (int i = n - 1; i > 0; i--) {
            t[i] = min(t[2 * i], t[2 * i + 1]);
        }
    }
    void change(int p, int x) {
        p += n;
        t[p] = x;
        p /= 2;
        while (p) {
            t[p] = min(t[2 * p], t[2 * p + 1]);
            p /= 2;
        }
    }
    int get_min(int l, int r) {
        if (r < 0) {
            return INF;
        }
        l = max(l, 0);
        r = min(r, n - 1);
        int res = INF;
        for (l += n, r += n; l <= r; l /= 2, r /= 2) {
            if (l % 2 == 1) {
                res = min(res, t[l++]);
            }
            if (r % 2 == 0) {
                res = min(res, t[r--]);
            }
        }
        return res;
    }
};

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
    int n, k;
    cin >> n >> k;
    vector <vector <int> > dp(2, vector <int> (n + 1, INF));
    vector <pair <int, int> > a(k);
    for (int i = 0; i < k; i++) {
        cin >> a[i].first >> a[i].second;
    }
    a.push_back({2 * n, 2 * n});
    dp[0][a[0].first] = 0;
    for (int i = 0; i < k; i++) {
        vector <vector <int> > ndp(2, vector <int> (n + 1, INF));
        Tree t1(n + 1), t2(n + 1);
        t1.build(dp[0]);
        t2.build(dp[1]);
        int tm = a[i].second - a[i].first;
        int add = a[i + 1].first - a[i].second;
        for (int j = 0; j <= n; j++) {
            ndp[1][j] = dp[1][j];
            ndp[1][j] = min(ndp[1][j], t1.get_min(max(0, j - tm), j) + 1);
            ndp[1][j] = min(ndp[1][j], t2.get_min(max(0, j - tm), j) + 2);
            if (j >= tm + add) {
                ndp[0][j] = dp[0][j - tm - add];
            }
            ndp[0][j] = min(ndp[0][j], t2.get_min(j - tm - add, j - add) + 1);
            ndp[0][j] = min(ndp[0][j], t1.get_min(j - tm - add, j - add) + 2);
        }
        dp = ndp;
    }
    int res = min(dp[0][n], dp[1][n]);
    if (res == INF) {
        cout << "Hungry\n";
        return 0;
    }
    cout << "Full\n";
    cout << res;
}