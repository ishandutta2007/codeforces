#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
using namespace std;
typedef long long LL;
const int MAXN = 200005;

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

int n, q, pos[MAXN], need[MAXN], w[MAXN];
LL cap[MAXN], reg[MAXN];

inline bool cmp(int x, int y) {
    return need[x] < need[y];
}

int tot, root[MAXN], lc[MAXN * 40], rc[MAXN * 40];
LL csum[MAXN * 40], rsum[MAXN * 40];

inline void pushup(int rt) {
    csum[rt] = csum[lc[rt]] + csum[rc[rt]];
    rsum[rt] = rsum[lc[rt]] + rsum[rc[rt]];
}

void Build(int &rt, int b, int e) {
    rt = ++tot;
    if (b == e) {
        rsum[rt] = reg[b];
        return;
    }
    int mid = (b + e) >> 1;
    Build(lc[rt], b, mid);
    Build(rc[rt], mid + 1, e);
    pushup(rt);
}

void Update(int &rt, int pre, int b, int e, int p) {
    rt = ++tot;
    if (b == e) {
        rsum[rt] = 0;
        csum[rt] = cap[b];
        return;
    }
    lc[rt] = lc[pre];
    rc[rt] = rc[pre];
    int mid = (b + e) >> 1;
    if (p <= mid) Update(lc[rt], lc[pre], b, mid, p);
    else Update(rc[rt], rc[pre], mid + 1, e, p);
    pushup(rt);
}

inline LL Calc(int rt, int dt) {
    return csum[rt] + rsum[rt] * dt;
}

LL Query(int rt, int b, int e, int l, int r, int dt) {
    if (l <= b && e <= r) return Calc(rt, dt);
    int mid = (b + e) >> 1;
    if (r <= mid) return Query(lc[rt], b, mid, l, r, dt);
    if (l > mid) return Query(rc[rt], mid + 1, e, l, r, dt);
    return Query(lc[rt], b, mid, l, r, dt) + Query(rc[rt], mid + 1, e, l, r, dt);
}

int Binary2(int rt, int b, int e, int l, int r, LL &hp, int dt) {
    if (b == e) return b;
    int mid = (b + e) >> 1;
    LL cur = Calc(lc[rt], dt);
    if (cur >= hp) return Binary2(lc[rt], b, mid, l, r, hp, dt);
    hp -= cur;
    return Binary2(rc[rt], mid + 1, e, l, r, hp, dt);
}

int Binary(int rt, int b, int e, int l, int r, LL &hp, int dt) {
    if (l <= b && e <= r) {
        LL cur = Calc(rt, dt);
        if (cur < hp) {
            hp -= cur; return 0;
        } else {
            return Binary2(rt, b, e, l, r, hp, dt);
        }
    }
    int mid = (b + e) >> 1;
    if (r <= mid) return Binary(lc[rt], b, mid, l, r, hp, dt);
    if (l > mid) return Binary(rc[rt], mid + 1, e, l, r, hp, dt);
    int ret = Binary(lc[rt], b, mid, l, r, hp, dt);
    if (ret) return ret;
    return Binary(rc[rt], mid + 1, e, l, r, hp, dt);
}

int lst[MAXN], rem[MAXN];
vector<int> S;

void solve() {
    read(n);
    for (int i = 1; i <= n; ++i) {
        read(cap[i]); read(reg[i]);
        need[i] = (cap[i] + reg[i] - 1) / reg[i];
        pos[i] = i;
    }
    sort(pos + 1, pos + n + 1, cmp);
    Build(root[0], 1, n);
    for (int i = 1; i <= n; ++i) {
        w[i] = need[pos[i]];
        Update(root[i], root[i - 1], 1, n, pos[i]);
    }
    S.push_back(n + 1);
    for (int i = n; i >= 1; --i) {
        S.push_back(i);
        rem[i] = cap[i];
    }

    LL ans = 0;
    read(q);
    while (q--) {
        int t; LL hp;
        read(t); read(hp);
        while (hp && S.size() > 1) {
            int l = S.back(), dt = t - lst[l];
            S.pop_back();
            int r = S.back() - 1;
            if (l == r) {
                LL cur = min(cap[l], rem[l] + reg[l] * dt);
                if (cur <= hp) {
                    hp -= cur;
                } else {
                    lst[l] = t;
                    rem[l] = cur - hp;
                    S.push_back(l);
                    hp = 0;
                }
            } else {
                int rnk = upper_bound(w + 1, w + n + 1, dt) - w - 1;
                LL sum = Query(root[rnk], 1, n, l, r, dt);
                if (sum <= hp) {
                    hp -= sum;
                } else {
                    int p = Binary(root[rnk], 1, n, l, r, hp, t - lst[l]);
                    if (p < r) {
                        lst[p + 1] = lst[l];
                        rem[p + 1] = 0;
                        S.push_back(p + 1);
                    }
                    LL cur = min(cap[p], reg[p] * dt);
                    if (cur > hp) {
                        lst[p] = t;
                        rem[p] = cur - hp;
                        S.push_back(p);
                    }
                    hp = 0;
                }
            }
        }
        ans += hp;
        if (S.back() != 1) {
            lst[1] = t;
            rem[1] = 0;
            S.push_back(1);
        }
        //printf("%lld\n", ans);
    }
    printf("%lld\n", ans);
}

int main() {
    solve();
    return 0;
}