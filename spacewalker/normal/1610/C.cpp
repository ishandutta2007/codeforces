#include <bits/stdc++.h>

using namespace std;

int solve() {
    int n; scanf("%d", &n);
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) scanf("%d %d", &a[i], &b[i]);
    int lo = 0, hi = n;
    while (lo < hi) {
        int mid = (lo + hi) / 2 + ((lo + hi) % 2);
        bool yes = (mid <= 1); // 0 is always possible
        if (mid > 1) {
//            printf("try mid %d\n", mid);
            int b1 = mid - 1, b2 = 0;
            for (int i = 0; i < n; ++i) {
                if (a[i] >= b1 && b[i] >= b2) {
//                    printf("%d picked\n", i);
                    b1--; b2++;
                    if (b1 == -1) break;
                }
            }
            if (b1 == -1) yes = true;
        }
        if (yes) lo = mid;
        else hi = mid - 1;
    }
    return lo;
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        printf("%d\n", solve());
    }
}