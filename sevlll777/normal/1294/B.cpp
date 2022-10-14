#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("unrool-loops")
#pragma GCC optimize("no-stack-limit")
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
#define int long long
#define pii pair<int, int>
#define tupint tuple<int, int, int>
#define tupint2 tuple<int, int, int, int>
#define str string
using namespace std;
const int M = 1000000007;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> X(n);
        vector<vector<int>> Y(n);
        for (int i = 0; i < n; i++) {
            int x, y; cin >> x >> y;
            X[i] = {x, y, i};
            Y[i] = {y, x, i};
        }
        str ans = "";
        sort(X.begin(), X.end());
        sort(Y.begin(), Y.end());
        bool f = true;
        for (int y = 0; y < n; y++) {
            if (X[y][2] != Y[y][2]) {
                f = false;
                break;
            }
        }
        if (!f) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            int lastx = 0;
            int lasty = 0;
            for (int i = 0; i < n; i++) {
                for (int j = lastx; j < X[i][0]; j++) {
                    cout << "R";
                }
                for (int j = lasty; j < Y[i][0]; j++) {
                    cout << "U";
                }
                lastx = X[i][0];
                lasty = Y[i][0];
            }
            cout << "\n";
        }
    }

}