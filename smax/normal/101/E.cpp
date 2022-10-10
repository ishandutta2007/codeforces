#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__)
#else
#define DEBUG(...) 6
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template <typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << s.substr(0, i) << " = " << x << " | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

const int MAX = 2e4;

int x[MAX], y[MAX], dp[MAX], ndp[MAX], diag[MAX];
vector<bool> par[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, p;
    cin >> n >> m >> p;
    for (int i=0; i<n; i++)
        cin >> x[i];
    for (int i=0; i<m; i++)
        cin >> y[i];

    int k = (n + m - 2) / 2;
    dp[0] = (x[0] + y[0]) % p;
    for (int d=1; d<=k; d++) {
        memset(ndp, 0, sizeof(ndp));
        for (int i=max(d-m+1, 0); i<=min(d, n-1); i++) {
            int j = d - i;
            if (i > 0) ndp[i] = max(ndp[i], dp[i-1]);
            if (j > 0) ndp[i] = max(ndp[i], dp[i]);
            ndp[i] += (x[i] + y[j]) % p;
        }
        memcpy(dp, ndp, sizeof(ndp));
    }
    memcpy(diag, dp, sizeof(dp));

    dp[n-1] = (x[n-1] + y[m-1]) % p;
    for (int d=n+m-3; d>=k; d--) {
        memset(ndp, 0, sizeof(ndp));
        for (int i=max(d-m+1, 0); i<=min(d, n-1); i++) {
            int j = d - i;
            if (i + 1 < n) ndp[i] = max(ndp[i], dp[i+1]);
            if (j + 1 < m) ndp[i] = max(ndp[i], dp[i]);
            ndp[i] += (x[i] + y[j]) % p;
        }
        memcpy(dp, ndp, sizeof(ndp));
    }

    pair<int, int> best(-1, -1);
    for (int i=max(k-m+1, 0); i<=min(k, n-1); i++) {
        int cur = diag[i] + dp[i] - (x[i] + y[k-i]) % p;
        if (cur > best.first)
            best = {cur, i};
    }

    dp[0] = (x[0] + y[0]) % p;
    for (int d=1; d<=k; d++) {
        memset(ndp, -1, sizeof(ndp));
        int l = max(d - m + 1, 0), r = min(d, n - 1);
        par[d-1].assign(r - l + 1, false);
        for (int i=l; i<=r; i++) {
            int j = d - i;
            if (i > 0 && dp[i-1] > ndp[i]) {
                ndp[i] = dp[i-1];
                par[d-1][i-l] = 1;
            }
            if (j > 0 && dp[i] > ndp[i]) {
                ndp[i] = dp[i];
                par[d-1][i-l] = 0;
            }
            ndp[i] += (x[i] + y[j]) % p;
        }
        memcpy(dp, ndp, sizeof(ndp));
    }

    string ret;
    int r = best.second, c = k - best.second;
    while (r > 0 || c > 0) {
        int l = max(r + c - m + 1, 0);
        if (par[r + c - 1][r - l]) {
            ret += 'C';
            r--;
        } else {
            ret += 'S';
            c--;
        }
    }
    reverse(ret.begin(), ret.end());

    dp[n-1] = (x[n-1] + y[m-1]) % p;
    for (int d=n+m-3; d>=k; d--) {
        memset(ndp, -1, sizeof(ndp));
        int l = max(d - m + 1, 0), r = min(d, n - 1);
        par[d-k].assign(r - l + 1, false);
        for (int i=l; i<=r; i++) {
            int j = d - i;
            if (i + 1 < n && dp[i+1] > ndp[i]) {
                ndp[i] = dp[i+1];
                par[d-k][i-l] = 1;
            }
            if (j + 1 < m && dp[i] > ndp[i]) {
                ndp[i] = dp[i];
                par[d-k][i-l] = 0;
            }
            ndp[i] += (x[i] + y[j]) % p;
        }
        memcpy(dp, ndp, sizeof(ndp));
    }

    r = best.second, c = k - best.second;
    while (r < n - 1 || c < m - 1) {
        int l = max(r + c - m + 1, 0);
        if (par[r + c - k][r - l]) {
            ret += 'C';
            r++;
        } else {
            ret += 'S';
            c++;
        }
    }
    cout << best.first << "\n" << ret << "\n";

    return 0;
}