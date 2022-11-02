#include <bits/stdc++.h>
using namespace std;

int n, a[20];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) scanf("%d", &a[i]);
    int m = 1 << n;
    bool fg = 0;
    for (int i = 0; i < m; i ++) {
        int sum = 0;
        for (int j = 0; j < n; j ++) {
            if (i & 1 << j) sum += a[j];
            else sum -= a[j];
        }
        if (sum % 360 == 0) fg = 1;
    }
    puts(fg ? "YES" : "NO");
}