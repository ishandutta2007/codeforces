#include <bits/stdc++.h>
using namespace std;
const int N = 500006;
int n, q, b[N][21], p[N][21];

inline void get(int x, int k, int r) {
    for (int i = 20; i >= 0; i--)
        if ((x >> i) & 1) {
            if (!b[r][i]) {
                b[r][i] = x;
                p[r][i] = k;
                return;
            }
            if (p[r][i] < k) {
                swap(p[r][i], k);
                swap(x, b[r][i]);
            }
            x ^= b[r][i];
        }
}

inline int work(int l, int r) {
    int ans = 0;
    for (int i = 20; i >= 0; i--)
        if (p[r][i] >= l) ans = max(ans, ans ^ b[r][i]);
    return ans;
}

int main() {
    cin >> n;
    for (int r = 1; r <= n; r++) {
        int x;
        scanf("%d", &x);
        memcpy(b[r], b[r-1], sizeof(b[r]));
        memcpy(p[r], p[r-1], sizeof(p[r]));
        get(x, r, r);
    }
    cin >> q;
    while (q--) {
        int l, r;
        scanf("%d %d", &l ,&r);
        printf("%d\n", work(l, r));
    }
    return 0;
}