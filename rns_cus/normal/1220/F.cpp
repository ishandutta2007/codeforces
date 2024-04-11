#include <bits/stdc++.h>
using namespace std;

#define N 200200

int n, a[N<<1], pre[N], suf[N], tot, st[N], b[N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) scanf("%d", &a[i]), a[n+i] = a[i];
    int shift;
    for (shift = 1; shift <= n; shift ++) if (a[shift] == 1) break;
    for (int i = 1; i <= n; i ++) a[i] = a[i+shift-1]; a[n+1] = 1;
    tot = 0; pre[1] = 1; st[++tot] = 1;
    for (int i = 2; i <= n; i ++) {
        int lst = 0;
        while (tot && a[st[tot]] > a[i]) {
            int u = st[tot]; tot --;
            b[u] = max(b[u], lst + 1);
            lst = b[u];
        }
        b[i] = lst + 1; st[++tot] = i;
        pre[i] = max(pre[i-1], lst + tot);
    }
    for (int i = 1; i <= n; i ++) b[i] = 0; tot = 0;
    suf[n+1] = 1; st[++tot] = n + 1;
    for (int i = n; i >= 2; i --) {
        int lst = 0;
        while (tot && a[st[tot]] > a[i]) {
            int u = st[tot]; tot --;
            b[u] = max(b[u], lst + 1);
            lst = b[u];
        }
        b[i] = lst + 1; st[++tot] = i;
        suf[i] = max(suf[i+1], lst + tot);
    }
    int mn = n + 1;
    for (int i = 1; i <= n; i ++) mn = min(mn, max(pre[i], suf[i+1]));
    int k;
    for (k = 1; k <= n; k ++) if (max(pre[k], suf[k+1]) == mn) break;
    printf("%d %d\n", mn, (k + shift - 1) % n);

    return 0;
}