#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>

#define pb push_back
// #define int long long
#define str string
using namespace std;
const int M = 1e9 + 7;


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int cntl = 0;
    for (auto c : s) {
        if (c == 'L') cntl++;
    }
    int cnt = -(cntl) * (cntl - 1) / 2;
    int mxs = 0;
    int cc = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'L') {
            cnt += i;
            mxs = max(mxs, i - cc);
            cc += 1;
        }
    }
    vector<vector<int>> ans;
    while (cnt != k) {
        k--;
        vector<int> turn;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == 'R' && s[i + 1] == 'L' && cnt > k) {
                cnt--;
                turn.pb(i + 1);
            }
        }
        if (turn.empty()) {
            cout << -1;
            return 0;
        }
        for (auto p : turn) {
            s[p - 1] = 'L';
            s[p] = 'R';
        }
        ans.pb(turn);
    }
    if (k < 0) {
        cout << -1;
        return 0;
    }
    while (k) {
        int f = 1;
        vector<int> op;
        for (int i = n - 1; i > 0; i--) {
            if (k && s[i - 1] == 'R' && s[i] == 'L') {
                op.pb({i});
                ans.pb({i});
                k--;
                f = 0;
            }
        }
        if (f && k) {
            cout << -1;
            return 0;
        }
        for (auto c : op) {
            s[c] = 'R';
            s[c - 1] = 'L';
        }
    }
    bool can = true;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == 'R' && s[i + 1] == 'L') {
            cout << -1;
            return 0;
        }
    }
    for (auto p : ans) {
        cout << p.size() << ' ';
        for (auto pp : p) cout << pp << ' ';
        cout << '\n';
    }


}