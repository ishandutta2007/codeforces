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
// #define int long long
#define ld long double
using namespace std;
const int M = 1000000007;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> C(n);
    for (int i = 0; i < n; i++) {
        cin >> C[i];
        C[i]--;
    }
    vector<int> right(n), left(n);
    for (int i = 0; i < n; i++) {
        left[i] = 1;
        right[i] = 1;
        int j = i - 1;
        int jj = i + 1;
        while (j >= 0 && C[j] == C[j + 1] - 1) {
            left[i]++;
            j--;
        }
        while (jj < n && C[jj] == C[jj - 1] + 1) {
            right[i]++;
            jj++;
        }
    }
    vector<vector<int>> sas;
    while (true) {
        bool ok = false;
        for (int i = 1; i < n; i++) {
            if (C[i - 1] > C[i]) ok = true;
        }
        if (!ok) break;
        for (int i = 1; i < n; i++) {
            if (!ok) break;
            int x = C[i];
            for (int j = 0; j < i; j++) {
                if (C[j] == x + 1) {
                    int r = right[j];
                    int l = left[i];
                    sas.pb({0, j, j + r, i + 1, n});
                    vector<int> b1, b2, b3, b5;
                    for (int p = 0; p < j; p++) b1.pb(C[p]);
                    for (int p = j; p < j + r; p++) b2.pb(C[p]);
                    for (int p = j + r; p < i + 1; p++) b3.pb(C[p]);
                    for (int p = i + 1; p < n; p++) b5.pb(C[p]);
                    C = {};
                    for (auto xx : b5) C.pb(xx);
                    for (auto xx : b3) C.pb(xx);
                    for (auto xx : b2) C.pb(xx);
                    for (auto xx : b1) C.pb(xx);
                    fill(left.begin(), left.end(), 0);
                    fill(right.begin(), right.end(), 0);
                    for (int i2 = 0; i2 < n; i2++) {
                        left[i2] = 1;
                        right[i2] = 1;
                        int j2 = i2 - 1;
                        int jj = i2 + 1;
                        while (j2 >= 0 && C[j2] == C[j2 + 1] - 1) {
                            left[i2]++;
                            j2--;
                        }
                        while (jj < n && C[jj] == C[jj - 1] + 1) {
                            right[i2]++;
                            jj++;
                        }
                    }
                    ok = false;
                    break;
                }
            }
        }
    }
    cout << sas.size() << '\n';
    for (auto p : sas) {
        vector<int> A;
        for (int d = 1; d < 5; d++) {
            if (p[d] > p[d - 1]) {
                A.pb(p[d] - p[d - 1]);
            }
        }
        cout << A.size() << ' ';
        for (auto x : A) cout << x << ' ';
        cout << '\n';
    }
}