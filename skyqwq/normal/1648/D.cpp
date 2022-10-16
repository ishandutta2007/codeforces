// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

template <typename T> bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }
template <typename T> bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 500005;

int n, q, a[4][N];

LL s[4][N], A[N], B[N], ans = -9e18;

vector<PII> e[N];

struct Node{
    LL a, b, mx;
} t[N << 2];

Node operator + (const Node &a, const Node &b) {
    Node c;
    c.a = max(a.a, b.a);
    c.b = max(a.b, b.b);
    // if (a.a + b.b == -2) {
    //     cout << a.a << " cao" << b.b << " wudi "  << "??\n";
    // }
    c.mx = max(max(a.mx, b.mx), a.a + b.b);
    return c;
}

#define ls (p << 1)
#define rs (p << 1 | 1)

void inline pushup(int p) {
    t[p] = t[ls] + t[rs];
}

void build(int p, int l, int r) {
    if (l == r) {
        t[p].a = A[r], t[p].b = B[r], t[p].mx = t[p].a + t[p].b;
        return;
    }
    int mid = (l + r) >> 1;
    build(ls, l, mid);
    build(rs, mid + 1, r);
    //cout << l << " " << r << "psp\n";
    pushup(p);
}

Node query(int p, int l, int r, int x, int y) {
    if (x <= l && r <= y) return t[p];
    int mid = (l + r) >> 1;
    if (y <= mid) return query(ls, l, mid, x, y);
    if (x > mid) return query(rs, mid + 1, r, x, y);
   //cout << "tr" << l << " " << r << " md\n";
    return query(ls, l, mid, x, y) + query(rs, mid + 1, r, x, y);
}

void change(int p, int l, int r, int x, LL k) {
    if (l == r) {
        chkMax(t[p].a, k);
        t[p].mx = t[p].a + t[p].b;
        return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid) change(ls, l, mid, x, k);
    else change(rs, mid + 1, r, x, k);
   // cout << l << " " << r << "psp2\n";
    pushup(p);
}

int main() {
    read(n), read(q);
    for (int i = 1; i <= 3; i++)
        for (int j = 1; j <= n; j++)
            read(a[i][j]), s[i][j] = s[i][j - 1] + a[i][j];
    for (int i = 1; i <= n; i++) {
        A[i] = s[1][i] - s[2][i - 1];
        B[i] = s[3][n] - s[3][i - 1] + s[2][i];
     //   cout << A[i] << " " << B[i] << " md\n";
    }
    build(1, 1, n);
    for (int i = 1; i <= q; i++) {
        int l, r, k; read(l), read(r), read(k);
        e[r].pb(mp(l, k));
    }
    for (int r = 1; r <= n; r++) {
        for (PII o: e[r]) {
            int l = o.fi, k = o.se;
            Node p = query(1, 1, n, l, r);
            chkMax(ans, p.mx - k);
            if (r < n) change(1, 1, n, r + 1, p.a - k);
        }
    }
    printf("%lld\n", ans);
    return 0;
}