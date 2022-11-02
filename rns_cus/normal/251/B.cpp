#include <bits/stdc++.h>

using namespace std;

#define N 111

int n, a[N], b[N], k;
int c[N], p[N], q[N];

bool run() {
    int x, y, i;
    for(i = 1; i <= n; i ++) p[i] = i;
    for(i = 0; i <= k; i ++) {
        int j;
            for(j = 1; j <= n; j ++) if(p[j] != b[j]) break;
            if(j > n) break;
        for(j = 1; j <= n; j ++) q[j] = p[a[j]];
        for(j = 1; j <= n; j ++) p[j] = q[j];
    }
    x = i;
    for(i = 1; i <= n; i ++) p[i] = i;
    for(i = 0; i <= k; i ++) {
        int j;
            for(j = 1; j <= n; j ++) if(p[j] != b[j]) break;
            if(j > n) break;
        for(j = 1; j <= n; j ++) q[j] = p[c[j]];
        for(j = 1; j <= n; j ++) p[j] = q[j];
    }
    y = i;
    if(x == 0 || y == 0) return 0;
    if(x > k && y > k) return 0;
    if(x == 1 && y == 1) return k == 1;
    if(x <= k && (k - x) % 2 == 0) return 1;
    if(y <= k && (y - k) % 2 == 0) return 1;
    return 0;
}

int main() {
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i ++) scanf("%d", a + i), c[a[i]] = i;
    for(int i = 1; i <= n; i ++) scanf("%d", b + i);
    if(run()) puts("YES"); else puts("NO");
    return 0;
}