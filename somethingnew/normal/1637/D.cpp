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
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()
void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> ab(n);
    for (int i = 0; i < n; ++i) {
        cin >> ab[i].first;
    }
    int sm = 0;
    for (int i = 0; i < n; ++i) {
        cin >> ab[i].second;
        if (ab[i].first > ab[i].second)
            swap(ab[i].first, ab[i].second);
        sm += ab[i].second - ab[i].first;
    }
    vector<vector<int>> ruc(n + 1, vector<int>(sm + 1, 0));
    vector<vector<int>> pre(n + 1, vector<int>(sm + 1, 0));
    ruc[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        int vl = ab[i].second - ab[i].first;
        for (int j = 0; j < sm; ++j) {
            if (ruc[i][j] == 1) {
                ruc[i + 1][j] = 1;
                pre[i + 1][j] = 0;
                ruc[i + 1][j + vl] = 1;
                pre[i + 1][j + vl] = 1;
            }
        }
    }
    int mabs = 1e9;
    int p = 0;
    for (int i = 0; i <= sm; ++i) {
        if (ruc.back()[i] == 1 and abs(sm - i * 2) <= mabs) {
            p = i;
            mabs = abs(sm - i * 2);
        }
    }
    int p1 = n;
    while (p1 != 0) {
        if (pre[p1][p]) {
            swap(ab[p1-1].first, ab[p1-1].second);
            p -= ab[p1-1].first - ab[p1-1].second;
        }
        p1--;
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            res += (ab[i].first + ab[j].first) * (ab[i].first + ab[j].first);
            res += (ab[i].second + ab[j].second) * (ab[i].second + ab[j].second);
        }
    }
    cout << res << '\n';
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    while (n--) solve();
}