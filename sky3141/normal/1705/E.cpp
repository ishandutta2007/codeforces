#include <iostream>
#include <algorithm>

using namespace std;

using LL = long long;

constexpr int MAXN = 200000 + 20 + 9, MAXA = 200025;

int n, q;
int a[MAXN];

struct Node
{
    int l, r;
    int sum;
    int lazy; // 0: none, 1: change0, 2: change1
    Node *lc, *rc;

    int size()
    {
        return r - l + 1;
    }
    void pushdown()
    {
        if (lazy)
        {
            if (lazy == 1)
            {
                lc->sum = 0;
                rc->sum = 0;
            }
            else
            {
                lc->sum = lc->size();
                rc->sum = rc->size();
            }
            lc->lazy = lazy;
            rc->lazy = lazy;
            lazy = 0;
        }
    }
    void update()
    {
        sum = lc->sum + rc->sum;
    }
} pool[MAXN * 2], *root, *alloc = pool;

Node* buildTree(int l, int r)
{
    Node *p = ++alloc;
    p->l = l;
    p->r = r;
    if (l == r)
    {
        // p->sum = 0;
        return p;
    }
    int mid = (l + r) >> 1;
    p->lc = buildTree(l, mid);
    p->rc = buildTree(mid + 1, r);
    p->update();
    return p;
}

void change0(Node *x, int l, int r)
{
    if (l <= x->l && x->r <= r)
    {
        x->sum = 0;
        x->lazy = 1;
        return ;
    }
    x->pushdown();
    if (l <= x->lc->r) change0(x->lc, l, r);
    if (r >= x->rc->l) change0(x->rc, l, r);
    x->update();
}

void change1(Node *x, int l, int r)
{
    if (l <= x->l && x->r <= r)
    {
        x->sum = x->size();
        x->lazy = 2;
        return ;
    }
    x->pushdown();
    if (l <= x->lc->r) change1(x->lc, l, r);
    if (r >= x->rc->l) change1(x->rc, l, r);
    x->update();
}

// LL query(Node *x, int l, int r)
// {
//     if (l <= x->l && x->r <= r)
//     {
//         return x->sum;
//     }
//     x->pushdown();
//     LL res = 0;
//     if (l <= x->lc->r) res += query(x->lc, l, r);
//     if (r >= x->rc->l) res += query(x->rc, l, r);
//     return res;
// }

int qnxt0(Node *x, int pos)
{
    if (x->l == x->r)
    {
        return x->sum == 0 ? x->l : 0;
    }
    if (x->l >= pos && x->sum == x->size())
    {
        return 0;
    }
    x->pushdown();
    if (x->lc->r >= pos)
    {
        int tmp = qnxt0(x->lc, pos);
        if (tmp)
            return tmp;
    }
    return qnxt0(x->rc, pos);
}

int qnxt1(Node *x, int pos)
{
    if (x->l == x->r)
    {
        return x->sum == 1 ? x->l : 0;
    }
    if (x->l >= pos && x->sum == 0)
    {
        return 0;
    }
    x->pushdown();
    if (x->lc->r >= pos)
    {
        int tmp = qnxt1(x->lc, pos);
        if (tmp)
            return tmp;
    }
    return qnxt1(x->rc, pos);
}

int qmax1(Node *x)
{
    if (x->l == x->r)
    {
        return x->sum ? x->l : 0;
    }
    if (x->sum == 0)
    {
        return 0;
    }
    x->pushdown();
    int t = qmax1(x->rc);
    if (t)
        return t;
    return qmax1(x->lc);
}

void add(int pos)
{
    int t = qnxt0(root, pos);
    if (t > pos)
    {
        change0(root, pos, t - 1);
    }
    change1(root, t, t);
}

void sub(int pos)
{
    int t = qnxt1(root, pos);
    if (t > pos)
    {
        change1(root, pos, t - 1);
    }
    change0(root, t, t);
}

int query()
{
    return qmax1(root);
}

void solve()
{
    cin >> n >> q;
    root = buildTree(1, MAXA);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        add(a[i]);
    }
    for (int i = 0; i < q; ++i)
    {
        int k, l;
        cin >> k >> l;
        sub(a[k]);
        add(l);
        a[k] = l;
        cout << query() << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }

    return 0;
}