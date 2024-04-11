#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define pb push_back
#define kek pop_back
#define mp make_pair
#define pii pair<int, int>
#define all(v) v.begin(), v.end()
#define len(v) ((int)(v).size())
#define int ll

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
const int INF = 1e9;

template<class t1, class t2>
bool cmin(t1 &a, const t2 &b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<class t1, class t2>
bool cmax(t1 &a, const t2 &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

#ifndef LOCAL
void UseFiles(const string &s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}
#else
void UseFiles(const string&) {}
#endif

void run();

signed main() {
    iostream::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    run();
}

string to_bin(int a) {
    string res;
    do {
        res += '0' + (a & 1);
        a >>= 1;
    } while (a);
    reverse(all(res));
    return res;
}

int calc_dp(int a, int b) {
    // if (a * b == 0) {
    //     return a + b + 1;
    // }
    string s1 = to_bin(a), s2 = to_bin(b);
    int n = max(len(s1), len(s2));
    s1 = string(n - len(s1), '0') + s1;
    s2 = string(n - len(s2), '0') + s2;
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(2, 0)));
    dp[0][1][1] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                if (j == 0 || s1[i] == '1') {
                    dp[i + 1][j][k && (s2[i] == '0')] += dp[i][j][k];
                }
                if (k == 0 || s2[i] == '1') {
                    dp[i + 1][j && (s1[i] == '0')][k] += dp[i][j][k];
                }
                dp[i + 1][j && (s1[i] == '0')][k && (s2[i] == '0')] += dp[i][j][k];
            }
        }
    }
    int ans = 0;
    for (auto &l : dp.back()) {
        for (auto &x : l) {
            ans += x;
        }
    }
    return ans;
}

int solve() {
    int l, r;
    cin >> l >> r;
    int ans = 0;
    ans += calc_dp(r, r);
    if (l != 0) {
        ans -= 2 * calc_dp(l - 1, r);
        ans += calc_dp(l - 1, l - 1);
    }
    return ans;
}

void run() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cout << solve() << endl;
    }
}