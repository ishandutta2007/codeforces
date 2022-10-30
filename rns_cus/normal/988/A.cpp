#include <bits/stdc++.h>
using namespace std;

#define N 105

int n, k, a[N], b[N], cnt;
bool vis[N];

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i ++) {
        scanf("%d", a + i);
        if (vis[a[i]]) continue;
        vis[a[i]] = 1;
        b[cnt ++] = i + 1;
    }
    if (cnt < k) puts("NO");
    else {
        puts("YES");
        for (int i = 0; i < k; i ++) printf("%d ", b[i]);
    }
}