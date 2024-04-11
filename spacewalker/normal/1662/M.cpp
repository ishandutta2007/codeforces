#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n, m; scanf("%d %d", &n, &m);
        vector<int> r(m), w(m);
        for (int i = 0; i < m; ++i) scanf("%d %d", &r[i], &w[i]);
        int rr = *max_element(begin(r), end(r)),
            ww = *max_element(begin(w), end(w));
        if (rr + ww > n) {
            printf("IMPOSSIBLE\n");
        } else {
            for (int i = 0; i < rr; ++i) printf("R");
            for (int i = 0; i < ww; ++i) printf("W");
            for (int i = 0; i < n - rr - ww; ++i) printf("R");
            printf("\n");
        }
    }
}