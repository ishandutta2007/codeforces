#include <bits/stdc++.h>
using namespace std;

#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
char buf[1 << 21], *p1 = buf, *p2 = buf;

inline int qread() {
    register char c = getchar();
    register int x = 0, f = 1;
    while (c < '0' || c > '9') {
        if (c == '-') f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = (x << 3) + (x << 1) + c - 48;
        c = getchar();
    }
    return x * f;
}

int n, a[500005], nxt[500005], stk[500005], stktop, st[21][250005], rpt[250005], idx[500005];

inline void buildMax() {
    for (int i = 1;i <= n;i++) st[0][i] = a[i];
    for (int k = 1;k <= 19;k++) {
        for (int i = 1;i <= n;i++) {
            if (i + (1 << k) - 1 > n) break;
            st[k][i] = max(st[k - 1][i], st[k - 1][i + (1 << k - 1)]);
        }
    }
}

inline void buildMin() {
    for (int i = 1;i <= n;i++) st[0][i] = a[i];
    for (int k = 1;k <= 19;k++) {
        for (int i = 1;i <= n;i++) {
            if (i + (1 << k) - 1 > n) break;
            st[k][i] = min(st[k - 1][i], st[k - 1][i + (1 << k - 1)]);
        }
    }
}

inline int queryMax(int l, int r) {
    int k = 31 - __builtin_clz(r - l + 1);
    return max(st[k][l], st[k][r - (1 << k) + 1]);
}

inline int queryMin(int l, int r) {
    int k = 31 - __builtin_clz(r - l + 1);
    return min(st[k][l], st[k][r - (1 << k) + 1]);
}

inline void Solve() {
    for (int i = 1;i <= n;i++) idx[a[i]] = i;
    stktop = 0;
    for (int i = 1;i <= n;i++) {
        while (stktop && a[i] > a[stk[stktop]]) {
            rpt[stk[stktop]] = i;
            stktop--;
        }
        stk[++stktop] = i;
    }
    while (stktop) rpt[stk[stktop--]] = n + 1;
    buildMin();
   //  for (int i = 1;i <= n;i++) cout << rpt[i] << " ";
    // cout << endl;
    // cout << queryMin(6, 10) << endl;
    for (int i = 1;i <= n;i++) nxt[i] = max(i + 1, idx[queryMin(i, rpt[i] - 1)]);
    
    stktop = 0;
    for (int i = 1;i <= n;i++) {
        while (stktop && a[i] < a[stk[stktop]]) {
            rpt[stk[stktop]] = i;
            stktop--;
        }
        stk[++stktop] = i;
    }
    while (stktop) rpt[stk[stktop--]] = n + 1;
    buildMax();
    for (int i = 1;i <= n;i++) nxt[i] = max(nxt[i], idx[queryMax(i, rpt[i] - 1)]);
    // for (int i = 1;i <= n;i++) cout << nxt[i] << " "; cout << endl;
}

int main() {
    int t = qread();
    while (t--) {
        n = qread();
        for (int i = 1;i <= n;i++) a[i] = qread();
        Solve();
        int u = 1, ans = 0;
        while (u != n) {
            u = nxt[u]; ans++;
        }
        cout << ans << endl;
    }
    return 0;
}