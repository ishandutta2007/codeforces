#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <set>
#include <queue>

using namespace std;

typedef long long ll;

void in(int& a)
{
    scanf("%d", &a);
}

void in(ll& a)
{
#ifdef ONLINE_JUDGE
    scanf("%I64d", &a);
#else
    scanf("%lld", &a);
#endif
}

void in(char* a)
{
    scanf("%s", a);
}

void out(int a)
{
    printf("%d ", a);
}

void out(ll a)
{
    printf("%lld ", a);
}

void out(const char* a)
{
    printf("%s ", a);
}

void newline(void)
{
    printf("\n");
}

template<class T> T gcd(T a, T b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}

// Insert correct MOD value here!
#define MOD 1000000007
// 998244353, ....
// Insert correct MOD value here!
#define mul(a, b) (((ll)(a) * (ll)(b)) % MOD)
#define inv(a) fpow(a, MOD-2)
int fpow(int base, int exponent)
{
    int ans = 1;
    int cur = base;
    while (exponent) {
        if (exponent & 1) ans = mul(ans, cur);
        cur = mul(cur, cur); exponent >>= 1;
    }
    return ans;
}

bool* filter_primes(int max_value)
{
    bool* composite = new bool[max_value + 10];
    for (int i = 1; i <= max_value; i++) composite[i] = false;
    for (int i = 2; i <= max_value; i++) {
        if (composite[i]) continue;
        for (int j = 2; i * j <= max_value; j++) {
            composite[i * j] = true;
        }
    }
    for (int i = 2; i <= max_value; i++) composite[i] = !composite[i];
    composite[1] = false;
    return composite;
}

int n;
int initval[200005];

struct Segtree {
    Segtree* lchild;
    Segtree* rchild;
    int l, r;
    int val;
    int min_op;
};

Segtree* root;

Segtree* build_st(int l, int r)
{
    Segtree* tree = new Segtree;
    tree->l = l; tree->r = r;
    if (l == r) {
        tree->lchild = tree->rchild = NULL;
        tree->val = initval[l];
    } else {
        tree->lchild = build_st(l, (l + r) / 2);
        tree->rchild = build_st((l + r) / 2 + 1, r);
        tree->val = 0;
    }
    tree->min_op = 0;
    return tree;
}

void pushdown(Segtree* st)
{
    if (st->min_op) {
        if (st->lchild == NULL) {
            st->val = max(st->val, st->min_op);
        } else {
            st->lchild->min_op = max(st->lchild->min_op, st->min_op);
            st->rchild->min_op = max(st->rchild->min_op, st->min_op);
        }
        st->min_op = 0;
    }
}

void modify(Segtree* st, int pos, int val)
{
    pushdown(st);
    if (st->l == st->r) {
        st->val = val;
    } else {
        if (pos <= (st->l + st->r) / 2) {
            modify(st->lchild, pos, val);
        } else {
            modify(st->rchild, pos, val);
        }
    }
}

void print_ans(Segtree* st)
{
    //printf("[%d, %d]: %d\n", st->l, st->r, st->min_op);
    pushdown(st);
    if (st->l == st->r) {
        out(st->val);
    } else {
        print_ans(st->lchild);
        print_ans(st->rchild);
    }
}

int main()
{
    in(n);
    for (int i = 1; i <= n; i++) in(initval[i]);
    root = build_st(1, n);
    int q;
    in(q);
    for (int i = 1; i <= q; i++) {
        int op, p, x;
        in(op);
        if (op == 1) {
            in(p); in(x); modify(root, p, x);
        } else {
            in(x);
            root->min_op = max(root->min_op, x);
        }
    }
    print_ans(root);
    return 0;
}

/* Before Submitting:
 * 1. Did the program use loop counters correctly?
 * 2. Does the program have variable name conflicts?
 * 3. Are all the arrays big enough?
 * 4. Did you use the correct integer type?
 * 5. Did you type incorrect variable names?
 * 6. Are you sure that your design is correct?
 *
 */