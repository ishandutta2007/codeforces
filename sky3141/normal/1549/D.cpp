#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;

using LL = long long;

constexpr int MAXN = 200000 + 9;

LL gcd(LL a, LL b)
{
    return b == 0 ? a : gcd(b, a % b);
}

struct Node
{
    int l, r;
    LL gcd;
    Node *lc, *rc;

    void update()
    {
        this->gcd = ::gcd(this->lc->gcd, this->rc->gcd);
    }
} pool[MAXN * 2], *root, *alloc = pool;

int n;
LL a[MAXN];

Node* buildTree(int l, int r)
{
    Node *p = ++alloc;
    p->l = l;
    p->r = r;
    if (l == r)
    {
        p->gcd = a[l];
        p->lc = p->rc = nullptr;
        return p;
    }
    int mid = (l + r) >> 1;
    p->lc = buildTree(l, mid);
    p->rc = buildTree(mid + 1, r);
    p->update();
    return p;
}

LL query(Node *x, int l, int r)
{
    if (l <= x->l && x->r <= r)
    {
        return x->gcd;
    }
    LL res = 0;
    if (l <= x->lc->r) res = gcd(query(x->lc, l, r), res);
    if (r >= x->rc->l) res = gcd(query(x->rc, l, r), res);
    return res;
}

void solve()
{
    alloc = pool;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    for (int i = n - 1; i > 0; --i)
    {
        a[i] -= a[i - 1];
        if (a[i] < 0) a[i] = -a[i];
    }
    a[n] = 1;
    root = buildTree(1, n);
    int r = 1, ans = 0;
    LL curgcd;
    for (int i = 1; i <= n; ++i)
    {
        curgcd = query(root, i, r);
        while (curgcd != 1)
        {
            ++r;
            curgcd = gcd(curgcd, a[r]);
        }
        ans = std::max(ans, r - i);
    }
    cout << ans + 1 << '\n';
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for (int i = 0; i < T; ++i)
    {
        solve();
    }

    return 0;
}