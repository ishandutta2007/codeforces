#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, sum = 0, mx = 0;
    scanf("%d", &n);
    for (int i = 0, x; i < n; i ++) scanf("%d", &x), sum += x, mx = max(mx, x);
    printf("%d\n", max(mx, 2 * sum / n + 1));
}