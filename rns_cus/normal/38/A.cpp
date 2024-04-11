#include <bits/stdc++.h>
using namespace std;

#define N 111

int n, d[N], a, b;

int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i ++) scanf("%d", &d[i]);
    scanf("%d %d", &a, &b);
    int ans = 0;
    for (int i = a; i < b; i ++) ans += d[i];
    printf("%d\n", ans);

    return 0;
}