#include <bits/stdc++.h>

using LL = long long;

const int max_N = (int) 2e5 + 21;

struct P {
    int x, y;

    explicit P(int x = 0, int y = 0) : x(x), y(y) {}

    P sub(const P &p) const { return P(x - p.x, y - p.y); }

    LL dot(const P &p) const { return 1ll * x * p.x + 1ll * y * p.y; }

    LL det(const P &p) const { return 1ll * x * p.y - 1ll * y * p.x; }

    bool operator<(const P &p) const {
        return x != p.x ? x < p.x : y < p.y;
    }
} p[2][max_N];

int n, m, st[2][max_N], top[2], fail[max_N];

std::pair<LL, LL> hash[2][max_N];

void convex(P *p, int n, int *st, int &top) {
    std::sort(p + 1, p + 1 + n);
    top = 0;
    auto check = [&](int i) -> bool {
        return p[i].sub(p[st[top - 1]]).det(p[st[top]].sub(p[st[top - 1]])) >= 0;
    };
    for (int i = 1; i <= n; ++i) {
        while (top > 1 && check(i)) --top;
        st[++top] = i;
    }
    for (int i = n - 1, tmp = top; i; --i) {
        while (top > tmp && check(i)) --top;
        st[++top] = i;
    }
    if (top > 1) --top;
}

void getHash(P *p, int *st, int top, std::pair<LL, LL> *hash) {
    st[top + 1] = st[1];
    st[top + 2] = st[2];
    for (int i = 1; i <= top; ++i) {
        hash[i].first = p[st[i + 1]].sub(p[st[i]]).dot(p[st[i + 2]].sub(p[st[i + 1]]));
        hash[i].second = p[st[i + 1]].sub(p[st[i]]).dot(p[st[i + 1]].sub(p[st[i]]));
    }
}

bool kmp(std::pair<LL, LL> *s, std::pair<LL, LL> *t, int n) {
    for (int i = 1; i <= n; ++i) s[n + i] = s[i];
    fail[1] = 0;
    for (int i = 2, j; i <= n; ++i) {
        for (j = fail[i - 1]; j && t[j + 1] != t[i]; j = fail[j]);
        if (t[j + 1] == t[i]) ++j;
        fail[i] = j;
    }
    for (int i = 1, j = 0; i <= 2 * n; ++i) {
        for (; j && t[j + 1] != s[i]; j = fail[j]);
        if (t[j + 1] == s[i] && ++j == n) return true;
    }
    return false;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%d%d", &p[0][i].x, &p[0][i].y);
    for (int i = 1; i <= m; ++i) scanf("%d%d", &p[1][i].x, &p[1][i].y);
    convex(p[0], n, st[0], top[0]), convex(p[1], m, st[1], top[1]);
    if (top[0] != top[1]) return puts("NO"), 0;
    getHash(p[0], st[0], top[0], hash[0]), getHash(p[1], st[1], top[1], hash[1]);
    puts(kmp(hash[0], hash[1], top[0]) ? "YES" : "NO");
    return 0;
}