#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define pii pair<int, int>
using namespace std;
typedef long long LL;
const int MAXN = 300005;

template <typename T> inline void read(T &WOW) {
    T x = 0, flag = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '0') flag = -1;
        ch = getchar();
    }
    while (isdigit(ch)) {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    WOW = flag * x;
}

char s[MAXN];
int n, q, tot, pos[MAXN], fa[MAXN], cnt[MAXN], cnt2[MAXN], son[MAXN], siz[MAXN];
int root[MAXN], id, lc[MAXN << 2], rc[MAXN << 2];
LL sum[MAXN << 2];

inline LL C2(LL x) {
    return x * (x + 1) / 2;
}

void Build(int &rt, int b, int e, int flag) {
    rt = ++id;
    if (b == e) {
        if (flag) sum[rt] = C2(cnt[b]);
        return;
    }
    int mid = (b + e) >> 1;
    Build(lc[rt], b, mid, flag);
    Build(rc[rt], mid + 1, e, flag);
    sum[rt] = sum[lc[rt]] + sum[rc[rt]];
}

void Update(int rt, int b, int e, int p, LL v) {
    sum[rt] += v;
    if (b == e) return;
    int mid = (b + e) >> 1;
    if (p <= mid) Update(lc[rt], b, mid, p, v);
    else Update(rc[rt], mid + 1, e, p, v);
}

LL Query(int rt, int b, int e, int l, int r) {
    if (l <= b && e <= r) return sum[rt];
    int mid = (b + e) >> 1;
    if (r <= mid) return Query(lc[rt], b, mid, l, r);
    if (l > mid) return Query(rc[rt], mid + 1, e, l, r);
    return Query(lc[rt], b, mid, l, r) + Query(rc[rt], mid + 1, e, l, r);
}

void solve() {
    read(n); read(q);
    scanf("%s", s + 1);
    int p = tot = 1;
    for (int i = 1; i <= n; ++i) {
        if (s[i] == '(') {
            fa[++tot] = p;
            son[tot] = ++cnt[p];
            pos[i] = p = tot;
        } else if (p != 1) {
            pos[i] = p;
            p = fa[p];
        }
    }
    Build(root[0], 1, tot, 1);
    for (int i = tot; i >= 1; --i) {
        ++siz[i];
        siz[fa[i]] += siz[i];
        cnt2[i] = cnt[i];
        if (cnt[i]) {
            Build(root[i], 1, cnt[i], 0);
        }
    }
    while (q--) {
        int type, l, r;
        read(type); read(l); read(r);
        if (type == 1) {
            int u = pos[l], f = fa[u];
            if (f) {
                Update(root[0], 1, tot, f, -cnt2[f]);
                --cnt2[f];
                Update(root[f], 1, cnt[f], son[u], 1);
            }
        } else {
            l = pos[l];
            r = pos[r];
            int f = fa[l];
            LL ans1 = Query(root[0], 1, tot, l, r + siz[r] - 1);
            LL ans2 = (f? C2(son[r] - son[l] + 1 - Query(root[f], 1, cnt[f], son[l], son[r])) : 0);
            printf("%lld\n", ans1 + ans2);
        }
    }
}

int main() {
    solve();
    return 0;
}