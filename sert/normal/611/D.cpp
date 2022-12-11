#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 5012;
const ll md = 1e9 + 7;

ll ds[N * 3];
int dp[N][N];

vector <int> z[N];
int n;
ll hlp;
string s;

bool cmp(int l, int m, int r) {
    if (l < 0)
        return true;
    int p = z[l][m - l];
    if (p >= m - l)
        return false;
    return s[l + p] < s[m + p];
}

vector <int> z_f(const string &s) {
    vector <int> ans;
    ans.push_back(0);
    int l, r;
    l = r = 0;
    for (int i = 1; i < s.length(); i++) {
        ans.push_back(0);
        ans[i] = min(max(0, r - i), ans[i - l]);
        while (s[ans[i]] == s[i + ans[i]])
            ans[i]++;
        if (i + ans[i] > r) {
            r = i + ans[i];
            l = i;
        }
    }
    return ans;
}

int main() {
    //freopen("a.in", "r", stdin);
    string t;
    cin >> n >> s;
    //cerr << s.length() << "\n";

    t = "@";
    for (int i = 0; i < n; i++) {
        t = s[n - i - 1] + t;
        //cerr << i << "\n";
        z[n - i - 1] = z_f(t);
    }
    //cerr << "z\n";

    dp[0][0] = 1;
    ds[0] = 1;
    for (int llen = 1; llen <= n; llen++)
    for (int len = 1; len <= n; len++) {
        if (llen > len)
            continue;
        if (s[len - llen] == '0') {
            dp[len][llen] = 0;
            continue;
        }
        dp[len][llen] = ds[len - llen];
        if (!cmp(len - llen * 2, len - llen, len))
            dp[len][llen] = (dp[len][llen] + md - dp[len - llen][llen]) % md;
        ds[len] = (ds[len] + dp[len][llen]) % md;
    }

    ll ans = 0;
    for (int llen = 1; llen <= n; llen++)
        ans = (ans + dp[n][llen]) % md;
    cout << ans;



    return 0;
}