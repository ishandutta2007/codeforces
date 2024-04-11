#include <bits/stdc++.h>
using namespace std;
#define N 2222
#define inf 1000000000
#define eps 1e-7
#define pi acos(-1)
#define gc getchar
#define pc putchar
#define pb push_back

typedef pair<int, int> pii;
typedef long long ll;

template <class T>
inline void chkmax(T &x, T y) {if (x < y) x = y;}

template <class T>
inline void chkmin(T &x, T y) {if (x > y) x = y;}

int n, a[N], tree[4*N];

int build(int v, int vl, int vr) {
    if (vl == vr) tree[v] = a[vl];
    else {
        int m = vl + vr >> 1;
        tree[v] = __gcd(build(v << 1, vl, m), build(v << 1 | 1, m + 1, vr));
    }
    return tree[v];
}

int query(int v, int vl, int vr, int l, int r) {
    if (l <= vl && vr <= r) return tree[v];
    if (l > vr || r < vl) return 0;
    int m = vl + vr >> 1;
    return __gcd(query(v << 1, vl, m, l, r), query(v << 1 | 1, m + 1, vr, l, r));
}

int main() {
    //freopen("1.in", "r", stdin);
    //freopen("11.out", "w", stdout);
    int i, fi = 0;
    scanf("%d", &n);
    for (i = 1; i <= n; i ++) scanf("%d", &a[i]);
    for (i = 1; i <= n; i ++)
        if (a[i] == 1) fi ++;
    if (fi) {
        printf("%d\n", n - fi);
        return 0;
    }
    build(1, 1, n);
    for (i = 1; i <= n; i ++)
        for (int j = 1; j <= n - i; j ++)
            if (query(1, 1, n, j, j + i) == 1) {
                printf("%d\n", i + n - 1);
                return 0;
            }
    puts("-1");

    return 0;
}