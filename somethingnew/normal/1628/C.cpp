#include <iostream>
#include "cmath"
#include "string"
#include "vector"
#include "set"
#include "algorithm"
#include "map"
#include "queue"
#include "array"
#include "numeric"
#include "iomanip"
using namespace std;
const int INF = 1e9 + 179;
#define all(x) x.begin(), x.end()
#define int long long
bool solve(vector<string> st) {
    int n = st.size();
    set<string> bl;
    for (int i = 0; i < n; ++i) {
        string s1 = st[i];
        reverse(all(s1));
        if (st[i] == s1)
            return 1;
        if (st[i].size() == 2) {
            if (bl.find(string(1, st[i][1])) != bl.end())
                return 1;
            reverse(all(st[i]));
            if (bl.find(st[i]) != bl.end())
                return 1;
            reverse(all(st[i]));
        }
        if (st[i].size() == 3) {
            string s1 = st[i];
            reverse(all(s1));
            if (bl.find(s1) != bl.end())
                return 1;
            s1.pop_back();
            if (bl.find(s1) != bl.end())
                return 1;
        }
        bl.insert(st[i]);
    }
    return 0;
}
void solve() {
    int n;
    cin >> n;
    vector<vector<int>> pole(n, vector<int>(n));
    int res = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> pole[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if ((i + j) % 4 == 0 and ((i % 2 == 0) == (i + j < n))) {
                res ^= pole[i][j];
            }
        }
    }
    //cout << (1 ^ 15 ^ 9) << endl;
    for (int i = 0; i < n; ++i) {
        reverse(all(pole[i]));
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if ((i + j) % 4 == 0 and ((i % 2 == 0) == (i + j < n))) {
                res ^= pole[i][j];
            }
        }
    }
    cout << res << '\n';
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    while (n--) solve();
}