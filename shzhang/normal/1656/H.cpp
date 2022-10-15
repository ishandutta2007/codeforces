#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cstdlib>
#include <utility>
#include <cmath>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;

#define ll __int128

#ifndef ONLINE_JUDGE
#define debug(format, ...) fprintf(stderr, \
    "%s:%d: " format "\n", __func__, __LINE__,##__VA_ARGS__)
#else
#define debug(format, ...)
#define NDEBUG
#endif

ll getbig()
{
    char s[50];
    scanf("%s", s);
    ll val = 0;
    for (int i = 0; s[i]; i++) {
        val *= (ll)10;
        val += (ll)(s[i] - '0');
    }
    return val;
}

ll GCD(ll a, ll b)
{
    if (b == 0) return a;
    return GCD(b, a % b);
}

ll LCM(ll a, ll b)
{
    return (a / GCD(a, b)) * b;
}

struct Segtree {
    int l, r, siz;
    ll* vals;
    Segtree* lchild;
    Segtree* rchild;
};

Segtree* build(int l, int r, int siz, ll* seq1, ll* seq2)
{
    Segtree* st = new Segtree;
    st->l = l; st->r = r; st->siz = siz;
    st->vals = new ll[siz + 1];
    if (st->l == st->r) {
        st->lchild = st->rchild = NULL;
        for (int i = 1; i <= siz; i++) {
            st->vals[i] = GCD(seq1[l], seq2[i]);
        }
    } else {
        st->lchild = build(l, (l + r) / 2, siz, seq1, seq2);
        st->rchild = build((l + r) / 2 + 1, r, siz, seq1, seq2);
        for (int i = 1; i <= siz; i++) {
            st->vals[i] = LCM(st->lchild->vals[i], st->rchild->vals[i]);
        }
    }
    return st;
}

void deactivate(Segtree* st, int pos)
{
    if (st->l == st->r) {
        for (int i = 1; i <= st->siz; i++) {
            st->vals[i] = 1;
        }
    } else {
        if (pos <= (st->l + st->r) / 2) {
            deactivate(st->lchild, pos);
        } else {
            deactivate(st->rchild, pos);
        }
        for (int i = 1; i <= st->siz; i++) {
            st->vals[i] = LCM(st->lchild->vals[i], st->rchild->vals[i]);
        }
    }
}

void putbig(ll x)
{
    if (!x) {
        printf("0 "); return;
    }
    int digits[50];
    int cur = 0;
    while (x) {
        digits[cur] = x % (ll)10;
        x /= (ll)10; cur++;
    }
    for (int i = cur - 1; i >= 0; i--) printf("%d", digits[i]);
    printf(" ");
}

ll a[1005], b[1005];
bool usea[1005], useb[1005];

Segtree* sta; Segtree* stb;

int n, m;

void outvals()
{
    for (int i = 1; i <= m; i++) {
        putbig(sta->vals[i]);
    }
    printf("\n");
    for (int i = 1; i <= n; i++) {
        putbig(stb->vals[i]);
    }
    printf("\n");
}

void work()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) a[i] = getbig();
    for (int i = 1; i <= m; i++) b[i] = getbig();
    for (int i = 1; i <= n; i++) usea[i] = true;
    for (int i = 1; i <= m; i++) useb[i] = true;
    sta = build(1, n, m, a, b);
    stb = build(1, m, n, b, a);
    while (true) {
        //outvals();
        bool worked = false;
        for (int i = 1; i <= m; i++) {
            if (sta->vals[i] != b[i] && useb[i]) {
                //printf("delete b %d\n", i);
                deactivate(stb, i);
                useb[i] = false; worked = true;
                //outvals();
            }
        }
        for (int i = 1; i <= n; i++) {
            if (stb->vals[i] != a[i] && usea[i]) {
                //printf("delete a %d\n", i);
                deactivate(sta, i);
                usea[i] = false; worked = true;
                //outvals();
            }
        }
        if (!worked) break;
    }
    int acnt = 0, bcnt = 0;
    for (int i = 1; i <= n; i++) if (usea[i]) acnt++;
    for (int i = 1; i <= m; i++) if (useb[i]) bcnt++;
    if (!acnt || !bcnt) {
        printf("NO\n");
    } else {
        printf("YES\n%d %d\n", acnt, bcnt);
        for (int i = 1; i <= n; i++) if (usea[i]) putbig(a[i]);
        printf("\n");
        for (int i = 1; i <= m; i++) if (useb[i]) putbig(b[i]);
        printf("\n");
    }
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}