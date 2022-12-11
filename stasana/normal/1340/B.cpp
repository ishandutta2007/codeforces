// Bipolar disorder is very cool

#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef int64_t ll;

inline void start() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}

string number[10] = {
    "1110111",
    "0010010",
    "1011101",
    "1011011",
    "0111010",
    "1101011",
    "1101111",
    "1010010",
    "1111111",
    "1111011"
};

ll to_try(string s, int x) {
    int result = 0;
    for (int i = 0; i < 7; ++i) {
        if (number[x][i] == '0' && s[i] == '1') {
            return -1;
        }
        if (number[x][i] == s[i]) {
            continue;
        }
        ++result;
    }
    return result;
}

inline void solve() {
    ll n, k;
    cin >> n >> k;
    vector<string> a(n);
    for (string& s : a) {
        cin >> s;
    }
    vector<set<int>> dp(n + 1);
    dp[n].insert(0);
    for (int i = n; i > 0; --i) {
        for (int x : dp[i]) {
            for (int id = 0; id < 10; ++id) {
                int delta = to_try(a[i - 1], id);
                if (delta == -1) {
                    continue;
                }
                if (delta + x > k) {
                    continue;
                }
                dp[i - 1].insert(delta + x);
            }
        }
    }
    if (dp[0].find(k) == dp[0].end()) {
        cout << -1 << endl;
        return;
    }
    vector<int> result;
    for (int i = 0; i < n; ++i) {
        for (int id = 9; id >= 0; --id) {
            int x = to_try(a[i], id);
            if (x == -1) {
                continue;
            }
            if (dp[i + 1].find(k - x) == dp[i + 1].end()) {
                continue;
            }
            k -= x;
            result.emplace_back(id);
            break;
        }
    }
    for (int i : result) {
        cout << i;
    }
    cout << endl;
}

int main() {
    start();
    solve();
    return 0;
}