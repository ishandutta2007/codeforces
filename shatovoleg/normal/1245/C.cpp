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

const int mod = 1e9 + 7;

void run() {
    string s;
    cin >> s;
    int n = len(s);
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 1; i < n; ++i) {
        dp[i + 1] += dp[i];
        if (s[i] == s[i - 1] && (s[i] == 'u' || s[i] == 'n')) {
            dp[i + 1] += dp[i - 1];
        }
        dp[i + 1] %= mod;
    }
    for (auto &x : s) {
        if (x == 'm' || x == 'w') {
            dp.back() *= 0;
        }
    }
    cout << dp.back() << endl;
}