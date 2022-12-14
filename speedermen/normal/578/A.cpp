#pragma GCC optimization ("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")

#include <bits/stdc++.h>

using namespace std;

const int MaxN = 1 << 18;

int main() {
//    freopen("input.txt", "r", stdin);
    int a, b;
    scanf("%d%d", &a, &b);
    double ans = 1e+42;
    if (a == b) {
        ans = b;
    } else {
        {
            int kk = (a - b) / (2 * b);
            for (int k = max(kk - 5, 1); 2LL * k * b + b <= a && k <= kk + 5; ++k) {
                ans = min(ans, 1.0 * (a - b) / (2 * k));
            }
        }
        {
            int kk = (a + b) / (2 * b);
            for (int k = max(kk - 5, 1); 2LL * k * b - b <= a && k <= kk + 5; ++k) {
                ans = min(ans, 1.0 * (a + b) / (2 * k));
            }
        }
    }
    if (ans > 1e+40) {
        printf("-1\n");
    } else {
        cout.precision(10);
        cout << fixed << ans << '\n';
    }
    return 0;
}