#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

const int MOD = 1e9 + 7;

int add(int a, int b) {
    a += b;
    if (a >= MOD)
        a -= MOD;
    return a;
}

int sub(int a, int b) {
    a -= b;
    if (a < 0)
        a += MOD;
    return a;
}

int mul(int a, int b) {
    return (ll) a * b % MOD;
}

int binpow(int a, int n) {
    int ans = 1;
    while (n) {
        if (n & 1) {
            ans = mul(ans, a);
        }
        a = mul(a, a);
        n >>= 1;
    }
    return ans;
}

int inv(int a) {
    return binpow(a, MOD - 2);
}

const int MAXN = 1e6 + 10;
const int MAXLOG = 20;

int dp[MAXN][MAXLOG];
int fact[MAXN], rfact[MAXN];
int lp[MAXN];
vector<int> p;

vector<int> gen(vector<pair<int, int>> & have, int now, int pos) {
    if (pos == have.size()) {
        if (now != 1) {
            return {now};
        } else {
            return {};
        }
    }
    vector<int> ans;
    for (int i = 0; i <= have[pos].second; i++) {
        auto fans = gen(have, now, pos + 1);
        if (fans.size() > ans.size()) swap(ans, fans);
        for (auto x : fans) {
            ans.push_back(x);
        }
        now *= have[pos].first;
    }
    return ans;
}

vector<int> gen(int x) {
    vector<pair<int, int>> have;
    while (x > 1) {
        if (have.empty() || have.back().first != lp[x]) {
            have.push_back({lp[x], 0});
        }
        have[have.size() - 1].second++;
        x /= lp[x];
    }
    return gen(have, 1, 0);
}

void build() {
    fact[0] = rfact[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = mul(fact[i - 1], i);
        rfact[i] = inv(fact[i]);
    }
    for (int i = 2; i < MAXN; i++) {
        if (lp[i] == 0) {
            lp[i] = i;
            p.push_back(i);
        }
        for (int j = 0; j < (int)p.size() && p[j] <= lp[i] && p[j] * i < MAXN; j++) {
            lp[p[j] * i] = p[j];
        }
    }
    for (int i = 1; i < MAXN; i++) {
        dp[i][0] = 1;
        auto have = gen(i);
        for (auto x : have) {
            if (x == i) continue;
            if (x == 1) continue;
            for (int j = 0; j < MAXLOG && dp[x][j] != 0; j++) {
                dp[i][j + 1] = add(dp[i][j + 1], dp[x][j]);
            }
        }
    }
}

int cnk(int n, int k) {
    return mul(fact[n], mul(rfact[k], rfact[n - k]));
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    build();
    int q;
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        int ans = 0;
        for (int i = 0; i < MAXLOG && dp[x][i] > 0 && i < y; i++) {
            ans = add(ans, mul(cnk(y, i + 1), dp[x][i]));
        }
        if (x == 1) ans = 1;
        ans = mul(ans, binpow(2, y - 1));
        cout << ans << "\n";
    }
    return 0;
}