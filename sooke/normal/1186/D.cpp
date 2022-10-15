#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>

const int N = 100005;

int n, a[N], b[N];
long long l, r, m;
double x;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lf", &x); a[i] = floor(x); b[i] = ceil(x);
        l += a[i]; r += b[i];
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] != b[i]) {
            if (l < 0) { l++; a[i]++; }
        }
        printf("%d\n", a[i]);
    }
    return 0;
}