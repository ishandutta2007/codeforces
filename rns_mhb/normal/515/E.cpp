#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 200005
#define x first
#define y second
#define f1(i, a, b) for (int i = a; i <= b; i ++)
template <class T> void chkmax(T &a, T b) {if (a < b) a = b;}
typedef pair <ll, ll> pll;
const ll linf = 2e18;

ll s[N], a[N], b[N];
int d[N], h[N];
ll mn[N<<2], mx[N<<2], e[N<<2];
int n, m;

void build(int l, int r, int seg) {
    if (l == r) {
         e[seg] = 0;
        mn[seg] = b[l], mx[seg] = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(l, mid, seg << 1);
    build(mid + 1, r, seg << 1 | 1);
    chkmax(e[seg], e[seg << 1]);
    chkmax(e[seg], e[seg << 1 | 1]);
    chkmax(e[seg], mx[seg << 1 | 1] - mn[seg << 1]);
    mx[seg] = max(mx[seg << 1], mx[seg << 1 | 1]);
    mn[seg] = min(mn[seg << 1], mn[seg << 1 | 1]);
    return;
}

ll ans;

pll query(int l, int r, int L, int R, int seg) {
    if (l <= L && R <= r) {
        chkmax(ans, e[seg]);
        return pll(mn[seg], mx[seg]);
    }
    int mid = L + R >> 1;
    pll rpt = pll(linf, 0), tpt = pll(linf, 0);
    if (l <= mid) rpt = query(l, r, L, mid, seg << 1);
    if (mid < r) tpt = query(l, r, mid + 1, R, seg << 1 | 1);
    chkmax(ans, tpt.y - rpt.x);
    return pll(min(rpt.x, tpt.x), max(rpt.y, tpt.y));
}

int main() {
    scanf("%d %d", &n, &m);
    f1(i, 1, n) scanf("%d", &d[i]);
    f1(i, 1, n) scanf("%d", &h[i]), h[i] <<= 1;
    int en = n * 2;
    f1(i, n + 1, en) h[i] = h[i-n], d[i] = d[i-n];
    f1(i, 1, en) s[i] = s[i-1] + d[i-1];
    f1(i, 1, en) a[i] = s[i] + h[i], b[i] = s[i] - h[i];
    build(1, en, 1);
    int x, y;
    f1(i, 1, m) {
        scanf("%d %d", &x, &y);
        if (x <= y) y ++, x = x + n - 1;
        else y ++, x --;
        ans = 0;
        query(y, x, 1, en, 1);
        printf("%I64d\n", ans);
    }
    return 0;
}