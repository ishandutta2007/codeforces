#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);
        vector<int> p(n);
        for (int i = 0; i < n; ++i) scanf("%d", &p[i]);
        for (int &v : p) --v;
        // beforeLEQ[i][v] = counts # of values before p[i] that are less than v
        // afterLEQ[i][v] = counts # of values after p[i] that are less than v
        vector<vector<int>> beforeLEQ(n, vector<int>(n)),
            afterLEQ(n, vector<int>(n));
        for (int i = 1; i < n; ++i) {
            beforeLEQ[i] = beforeLEQ[i-1];
            for (int k = p[i-1] + 1; k < n; ++k) {
                beforeLEQ[i][k]++;
            }
        }
        for (int i = n - 2; i >= 0; --i) {
            afterLEQ[i] = afterLEQ[i+1];
            for (int k = p[i+1] + 1; k < n; ++k) {
                afterLEQ[i][k]++;
            }
        }
        ll ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                ans += beforeLEQ[i][p[j]] * afterLEQ[j][p[i]];
            }
        }
        printf("%lld\n", ans);
    }
}