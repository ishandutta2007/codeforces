#include<bits/stdc++.h>

using namespace std;

#define int long long

const int INF = 2e18 + 7;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            char c;
            cin >> c;
            a[i][j] = c - '0';
        }
    }
    vector<vector<int>> d(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            d[i][j] = a[i][j];
            if (d[i][j] == 0 && i != j) {
                d[i][j] = INF;
            }
        }
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    int m;
    cin >> m;
    vector<int> p(m);
    for (int i = 0; i < m; ++i) {
        cin >> p[i];
        --p[i];
    }
    vector<int> prv(m);
    for (int i = 0; i < m; ++i) {
        prv[i] = i;
        int l = -1, r = i - 1;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (i - mid <= d[p[mid]][p[i]]) {
                r = mid;
            } else {
                l = mid;
            }
        }
        prv[i] = r;
    }
    vector<int> dp(m);
    vector<int> from(m);
    dp[0] = 1;
    from[0] = -1;;
    int cL = 0, cR = 0;
    deque<int> q;
    q.push_back(0);
    for (int i = 1; i < m; ++i) {
        int nL = prv[i], nR = i - 1;
        while (cR < nR) {
            ++cR;
            while (!q.empty() && dp[q.back()] > dp[cR]) {
                q.pop_back();
            }
            q.push_back(cR);
        }
        while (cL < nL) {
            if (!q.empty() && q.front() == cL) {
                q.pop_front();
            }
            ++cL;
        }
        dp[i] = dp[q.front()] + 1;
        from[i] = q.front();
        ++cR;
        while (!q.empty() && dp[q.back()] > dp[cR]) {
            q.pop_back();
        }
        q.push_back(cR);
    }
    vector<int> v;
    for (int i = m - 1; i > -1; i = from[i]) {
        v.push_back(p[i]);
    }
    reverse(v.begin(), v.end());
    cout << (int)v.size() << endl;
    for (auto &vv : v) {
        cout << vv + 1 << " ";
    }
    return 0;
}