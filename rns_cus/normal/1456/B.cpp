#include <bits/stdc++.h>
using namespace std;

#define N 100100

int n, a[N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    int d;
    for (d = 1; d <= 70 && d <= n - 2; d ++) {
        for (int k = 1; k < n; k ++) {
            int le = 0, ri = a[k+1];
            for (int i = 0; i <= d; i ++) if (k > i) le ^= a[k-i];
            for (int x = d + 1; x >= 1; x --) {
                if (k >= x && k + d + 2 - x <= n &&  le > ri) return printf("%d\n", d), 0;
                if (k >= x) le ^= a[k-x+1];
                if (k + d + 3 - x <= n) ri ^= a[k+d+3-x];
            }
        }
    }
    puts("-1");

    return 0;
}