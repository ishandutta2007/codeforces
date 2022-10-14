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
#include <bitset>

#define pb push_back
#define int long long
#define ld long double
using namespace std;
const int M = 1000000007;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> A(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> A[i][j];
            }
        }
        bool ok = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int g = 4;
                if (i == 0 || i == n - 1) g--;
                if (j == 0 || j == m - 1) g--;
                ok &= (A[i][j] <= g);
                A[i][j] = g;
            }
        }
        if (!ok) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            for (auto p : A) {
                for (auto x : p) {
                    cout << x << ' ';
                }
                cout << '\n';
            }
        }
    }
}