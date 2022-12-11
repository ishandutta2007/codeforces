#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 34;
const ll md = 1e9 + 9;
const ll p = 10;

ll h[N];
ll a[N];
bool u[N];
ll bh[N];
ll st[N];
char s[N];
int n;

void push(int v, int l, int r) {
    if (!u[v])
        return;
    u[v] = false;
    u[v * 2 + 1] = true;
    u[v * 2 + 2] = true;
    a[v * 2 + 2] = a[v];
    a[v * 2 + 1] = a[v];
    h[v * 2 + 1] = (bh[(l + r) / 2 - l]  * (a[v] + 1)) % md;
    h[v * 2 + 2] = (bh[r - (l + r) / 2]  * (a[v] + 1)) % md;
}

void add(int v, int l, int r, int L, int R, int x) {
    if (l >= R || L >= r) return;
    if (L <= l && r <= R) {
        a[v] = x;
        u[v] = true;
        h[v] = (bh[r - l] * (x + 1)) % md;
        return;
    }
    push(v, l, r);
    int m = (l + r) / 2;
    add(v * 2 + 1, l, m, L, R, x);
    add(v * 2 + 2, m, r, L, R, x);
    h[v] = (h[v * 2 + 1] * st[r - m] + h[v * 2 + 2]) % md;
}

int geth(int v, int l, int r, int L, int R) {
    if (L >= r || l >= R) {
        //cout << "zero\n" << l << " " << r << " " << L << " " << R << "\n";
        return 0;
    }
    if (L <= l && r <= R)
        return h[v];
    push(v, l, r);
    int m = (l + r) / 2;
    //cout << "ee: " << min(r, R) - max(L, m) << "\n";
    return (geth(v * 2 + 1, l, m, L, R) * st[max(0, min(r, R) - max(L, m))] + geth(v * 2 + 2, m, r, L, R)) % md;
}

bool eq(int l, int r, int d) {
    // cout << "q: " << l << " " << r << " " << d << " n:" << n << "\n";
    // cout << geth(0, 0, n, l + d, r) << " " << geth(0, 0, n, l, r - d) << "\n";
    return geth(0, 0, n, l + d, r) == geth(0, 0, n, l, r - d);
}

void build(int v, int l, int r) {
    if (l + 1 == r) {
        h[v] = s[l] - '0' + 1;
        return;
    }
    int m = (l + r) / 2;
    build(v * 2 + 1, l, m);
    build(v * 2 + 2, m, r);
    h[v] = (h[v * 2 + 1] * st[r - m] + h[v * 2 + 2]) % md;
}


int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);

    int m, m0, l, d, r, t;    
    
    scanf("%d%d%d", &n, &m, &m0);
    scanf("%s", s);
    st[0] = 1;
    for (int len = 1; len <= n; len++) {
        bh[len] = (bh[len - 1] * p + 1) % md;
        st[len] = (st[len - 1] * p) % md;
    }

    build(0, 0, n);

    // for (int i = 0; i < 34; i++)
    //     cout << h[i] << " ";
    // cout << "\n";

    m += m0;
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d%d", &t, &l, &r, &d);
        if (t == 1) {
            add(0, 0, n, l - 1, r, d);
        } else {
            if (eq(l - 1, r, d))
                printf("YES\n");
            else
                printf("NO\n");
        }
    }


    return 0;
}