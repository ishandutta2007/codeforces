#include <bits/stdc++.h>
using namespace std;

#define N 1050000
#define D 1000

typedef long long ll;
typedef pair<int, int> pii;
int n, q, k;
int a[N];
ll now;
int cnt[N];
ll ans[N];

struct query{
    int l, r, id;
    bool operator< (const query &b) const {
        return pii(l / D, r) < pii(b.l / D, b.r);
    }
} b[N];

int L, R;

void add(int x, int fg) {
    now += fg * cnt[x^k];
    if (fg == -1 && !k) now ++;
    cnt[x] += fg;
}

void go(int l, int r) {
    while (R < r) add(a[++R], 1);
    while (l < L) add(a[--L], 1);
    while (r < R) add(a[R--], -1);
    while (L < l) add(a[L++], -1);
}

int main() {
    scanf("%d %d %d", &n, &q, &k);
    for (int i = 1; i <= n; i ++) {
        scanf("%d", &a[i]);
        a[i] ^= a[i-1];
    }
    for (int i = 0; i < q; i ++) {
        scanf("%d %d", &b[i].l, &b[i].r);
        b[i].l --;
        b[i].id = i;
    }
    L = 0, R = -1;
    sort(b, b + q);
    for (int i = 0; i < q; i ++) {
        go(b[i].l, b[i].r);
        ans[b[i].id] = now;
    }
    for (int i = 0; i < q; i ++) printf("%I64d\n", ans[i]);
    return 0;
}