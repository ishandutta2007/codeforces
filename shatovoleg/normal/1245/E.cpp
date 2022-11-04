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

pii get_by_num (int n) {
    int x = n / 10;
    n %= 10;
    if (x & 1) {
        return {x, 10 - n - 1};
    } else {
        return {x, n};
    }
}

int get_num(int x, int y) {
    int n = x - x % 2;
    n *= 10;
    x %= 2;
    if (x == 0) {
        n += y;
    } else {
        n += 20 - y - 1;
    }
    return n;
}

void run() {
    vector<vector<int>> fld(10, vector<int>(10, 0));
    for (auto &l : fld) {
        for (auto &x : l) {
            cin >> x;
        }
    }
    vector<ld> dp(100, 0);
    for (int i = 1; i < 6; ++i) {
        dp[i] = 6;
    }
    for (int i = 6; i < 100; ++i) {
        for (int res = 1; res <= 6; ++res) {
            auto [x, y] = get_by_num(i - res);
            int idx = get_num(x - fld[x][y], y);
            dp[i] += min(dp[i - res], dp[idx]);
        }
        dp[i] /= 6;
        dp[i] += 1;
    }
    cout << fixed << setprecision(10) << dp.back() << endl;
}