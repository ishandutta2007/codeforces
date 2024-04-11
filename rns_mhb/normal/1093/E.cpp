#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree <int, null_type, less <int>, rb_tree_tag, tree_order_statistics_node_update> ST;

#define N 200020

int n, m, a[N], b[N];
ST s[N];

inline char nc() {
    static char buf[100000],*p1 = buf,*p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++;
}
inline bool read(int &x) {
    char c = nc(), b = 1;
    for (; !(c >= '0' && c <= '9'); c = nc()) {
        if (c == '-') b = -b;
        if (c == -1) return 0;
    }
    for (x = 0; c >= '0' && c <= '9'; x = x * 10 + c - '0', c = nc()); x *= b;
    return 1;
}

void build() {
    for (int i = 1; i <= n; i ++) {
        int dn = i - (i & -i);
        for (int j = i; j > dn; j --) s[i].insert(a[j]);
    }
}

int query(int k, int x, int y) {
    int rlt = 0;
    for (; k; k -= k & -k) rlt += s[k].order_of_key(y + 1) - s[k].order_of_key(x);
    return rlt;
}

void erase(int k) {
    int x = a[k];
    for (; k <= n; k += k & -k) s[k].erase(x);
}

void insert(int k) {
    int x = a[k];
    for (; k <= n; k += k & -k) s[k].insert(x);
}

int main() {
    read(n), read(m);
    for (int i = 1, x; i <= n; i ++) read(x), b[x] = i;
    for (int i = 1, x; i <= n; i ++) read(x), a[i] = b[x];
    build();
    while (m --) {
        int q, x, y, l, r;
        read(q);
        if (q == 1) {
            read(x), read(y), read(l), read(r);
            printf("%d\n", query(r, x, y) - query(l - 1, x, y));
        }
        else {
            read(x), read(y);
            l = a[x], r = a[y];
            erase(x), erase(y);
            a[x] = r, a[y] = l;
            insert(x), insert(y);
        }
    }
    return 0;
}