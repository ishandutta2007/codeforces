#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define debug(x) cerr << #x << " = " << x << ", line = " << __LINE__ << endl

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int SZ = 200005;
const LL INF = 1e18;

struct Node {
    LL res;
    LL f1, f2;
    Node *left, *right;
    Node() {
        res=-1;
        f1=f2=-INF;
    }
};

int n, m;
Node st[2 * SZ];
Node none;
LL h[SZ];
LL d[SZ];

Node combine(Node a, Node b) {
    if (a.res == -1 && b.res != -1) {
        return b;
    }
    if (b.res == -1 && a.res != -1) {
        return a;
    }
    Node r;
    r.res = max(a.res, b.res);
    r.res = max(r.res, b.f1 + a.f2);
    r.f1 = max(a.f1, b.f1);
    r.f2 = max(a.f2, b.f2);
    return r;
}

void build(int i, int l, int r) {
    if (l == r) {
        st[i].res = 0;
        st[i].f1 = 2 * h[l] + d[l];
        st[i].f2 = 2 * h[l] - d[l];
        return;
    }

    int m = (l + r) >> 1;
    int li = i + 1, ri = i + 2 * (m - l + 1);
    build(li, l, m);
    build(ri, m+1, r);

    st[i] = combine(st[li], st[ri]);
}

Node get(int i, int l, int r, int ql, int qr) {
    if (ql > qr) {
        return none;
    }
    if (l == ql && r == qr) {
        return st[i];
    }
    int m = (l + r) >> 1;
    int li = i + 1, ri = i + 2 * (m - l + 1);
    Node res = get(li, l, m, ql, min(m, qr));
    res = combine(res, get(ri, m+1, r, max(ql, m+1), qr));
    return res;
}

LL solve(int a, int b) {
    int x, y;
    if (a <= b) {
        x = b + 1;
        y = n + a - 1;
    } else {
        x = b + 1;
        y = a - 1;
    }
    assert(x < y);

    Node result = get(1, 0, 2 * n - 1, x, y);
    return result.res;
}

int main() {
    setIO();
    cin>>n>>m;

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        d[i+1] = d[n+i+1] = x;
    }
    for (int i = 0; i < 2 * n; i++) {
        d[i+1] += d[i];
    }

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        h[i] = h[n+i] = x;
    }

    build(1, 0, 2 * n - 1);

    for (int i = 0; i < m; i++) {
        int ql, qr;
        cin >> ql >> qr;
        cout << solve(ql-1, qr-1) << endl;
    }
    return 0;
}