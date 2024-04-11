#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int MOD = 998244353;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

void add(int &x, int y) {
    x += y;
    if (x >= MOD) {
        x -= MOD;
    }
}

vector <int> zfunc(string &s) {
    int n = s.size();
    vector <int> z(n, 0);
    int l = -1, r = -1;
    for (int i = 1; i < n; i++) {
        if (i <= r) {
            z[i] = min(z[i - l], r - i + 1);
        }
        while (i + z[i] < n && s[i + z[i]] == s[z[i]]) {
            z[i]++;
        }
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
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
    string a, l, r;
    cin >> a >> l >> r;
    int n = a.size(), m = l.size(), k = r.size();
    vector <bool> gl(n, false), gr(n, false);
    string la = l + "#" + a;
    string ra = r + "#" + a;
    auto zl = zfunc(la), zr = zfunc(ra);
    for (int i = 0; i < n; i++) {
        if (i + m > n) continue;
        if (a[i] == '0' && m != 1) {
            continue;
        }
        int len = zl[m + 1 + i];
        if (len == m || l[len] < a[i + len]) {
            gl[i] = true;
        }
    }
    //cout << "\n";
    for (int i = 0; i < n; i++) {
        if (i + k > n) continue;
        if (a[i] == '0' && k != 1) {
            continue;
        }
        int len = zr[k + 1 + i];
        if (len == k || r[len] > a[i + len]) {
            gr[i] = true;
        }
        //cout << gr[i];
    }
    //cout << "\n";
    vector <int> dp(n + 1, 0);
    dp[0] = 1;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        if (k - m >= 2) {
            if (i >= k && a[i - k] != '0') {
                add(sum, MOD - dp[i - k]);
            }
            if (i >= m + 1 && a[i - m - 1] != '0') {
                add(sum, dp[i - m - 1]);
            }
        }
        add(dp[i], sum);
        if (k != m) {
            if (i >= k && gr[i - k]) {
                add(dp[i], dp[i - k]);
            }
            if (i >= m && gl[i - m]) {
                add(dp[i], dp[i - m]);
            }
        } else if (i >= k && gr[i - k] && gl[i - k]) {
            add(dp[i], dp[i - k]);
        }
        //cout << i << " " << dp[i] << "\n";
    }
    cout << dp[n];
}