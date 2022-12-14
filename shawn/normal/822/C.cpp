#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int rd() {
    int x = 0; char c = getchar();
    while (c > '9' || c < '0') c = getchar();
    while (c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
    return x;
}

const int N = 2e5 + 10;
const int inf = 2e9 + 10;

struct Node {
    int p, l, c, t;
    bool operator < (const Node &a) const {
        return p < a.p || (p == a.p && t < a.t);
    }
} a[N << 1];
int n, x, f[N];
long long ans;

int main() {
    n = rd(), x = rd();
    for (int i = 1; i <= n; i ++) {
        int l = rd(), r = rd(), c = rd();
        a[2 * i - 1].p = l, a[2 * i].p = r;
        a[2 * i - 1].l = r - l + 1, a[2 * i].l = r - l + 1;
        a[2 * i - 1].c = c, a[2 * i].c = c;
        a[2 * i - 1].t = -1, a[2 * i].t = 1;
    }
    sort(a + 1, a + 2 * n + 1);
    fill(f + 1, f + x + 1, inf);
    ans = inf;
    for (int i = 1; i <= 2 * n; i ++) {
        if (a[i].l >= x) continue;
        if (a[i].t == -1) ans = min(ans, 1ll * a[i].c + 1ll * f[x - a[i].l]);
        else f[a[i].l] = min(f[a[i].l], a[i].c);
    }
    printf("%lld\n", ans == inf ? -1 : ans);
    return 0;
}