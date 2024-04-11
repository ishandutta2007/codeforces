#include <bits/stdc++.h>

using namespace std;
using ld = long double;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);
        vector<int> miners, diamonds;
        for (int i = 0; i < 2 * n; ++i) {
            int x, y; scanf("%d %d", &x, &y);
            if (x == 0) {
                miners.push_back(abs(y));
            } else diamonds.push_back(abs(x));
        }
        sort(begin(miners), end(miners));
        sort(begin(diamonds), end(diamonds));
        ld ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += hypot((ld)miners[i], (ld)diamonds[i]);
        }
        printf("%.12Lf\n", ans);
    }
}