#pragma GCC optimize("O3")
#pragma GCC target("avx")

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define N 400010
#define U (4 * N)

int read_char() {
    static char buf[1 << 16], *ptr = buf, *end_ptr = buf;
    if (ptr == end_ptr) {
        int len = fread(buf, 1, sizeof(buf), stdin);
        if (len <= 0) return EOF;
        ptr = buf;
        end_ptr = buf + len;
    }
    return *ptr++;
}

inline int read_int() {
#undef getchar_unlocked
#define getchar_unlocked read_char
    int ch;
    do {
        ch = getchar_unlocked();
    } while (ch < '0' || ch > '9');
    int x = ch - '0';
    while (1) {
        ch = getchar_unlocked();
        if (ch < '0' || ch > '9') break;
        x = x * 10 + ch - '0';
    }
    return x;
}


typedef struct Seg {
    struct Seg *lc, *rc;
    int cnt;
    uint8_t mark, bl, br;
} seg_t;

seg_t mem[10 * N], *ptr = mem;

seg_t* new_seg() {
    return ptr++;
}

int ql, qr;
void ins(seg_t *t, int l, int r) {
    if (t->mark) return;
    if (ql <= l && r <= qr) {
        t->cnt = t->mark = t->bl = t->br = 1;
        return;
    }
    int m = (0LL + l + r) / 2;
    if (!t->lc) t->lc = new_seg();
    if (!t->rc) t->rc = new_seg();
    if (ql <= m) ins(t->lc, l, m);
    if (qr > m) ins(t->rc, m + 1, r);
    if (t->lc->mark && t->rc->mark) {
        t->cnt = t->mark = t->bl = t->br = 1;
    } else {
        t->cnt = t->lc->cnt + t->rc->cnt - (t->lc->br && t->rc->bl);
        t->mark = 0;
        t->bl = t->lc->bl;
        t->br = t->rc->br;
    }
}

void msort(int a[], int l, int r) {
    if (l + 1 >= r) return;
    static int b[2 * N];
    int m = (l + r) / 2;
    msort(a, l, m);
    msort(a, m, r);
    for (int i = l; i < r; i++) b[i] = a[i];
    for (int i = l, j = m, k = l; i < m || j < r; k++) {
        if (i < m && (j == r || b[i] < b[j])) a[k] = b[i++];
        else a[k] = b[j++];
    }
}

int m, a[2 * N];

int conv(int x) {
    int l = 0, r = m - 1;
    while (l != r) {
        int mid = (l + r) / 2;
        if (a[mid] < x) l = mid + 1;
        else r = mid;
    }
    return l + 1;
}

int n, l[N], r[N];

int main() {
    n = read_int();
    for (int i = 0; i < n; i++) {
        l[i] = read_int();
        r[i] = read_int();
    }
    for (int i = 0; i < n; i++) {
        a[i] = l[i];
        a[i + n] = r[i];
    }
    msort(a, 0, 2 * n);
    for (int i = 0; i < 2 * n; i++) {
        if (i == 0 || a[i] != a[i - 1]) {
            a[m++] = a[i];
        }
    }
    for (int i = 0; i < n; i++) {
        l[i] = conv(l[i]);
        r[i] = conv(r[i]);
    }
    seg_t *root = new_seg();
    for (int i = 0; i < n; i++) {
        ql = l[i] * 2;
        qr = r[i] * 2;
        // printf("%d %d\n", ql, qr);
        ins(root, 1, U);
        int ans = root->cnt;
        printf("%d%c", ans, i == n - 1 ? '\n' : ' ');
    }
    return 0;
}