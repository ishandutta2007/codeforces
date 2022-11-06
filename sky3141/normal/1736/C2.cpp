#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using pii = pair<int, int>;

constexpr int N = 200000 + 9;

int n;
int a[N];
int prefmx[N];
LL sum[N];
LL suff[N];

struct Node
{
    int l, r;
    int mx;
    Node *lc, *rc;

    void update()
    {
        mx = max(lc->mx, rc->mx);
    }
} *root, pool[N * 2], *alloc = pool;

Node* buildTree(int l, int r)
{
    Node *p = ++alloc;
    p->l = l;
    p->r = r;
    if (l == r)
    {
        p->mx = a[l];
        return p;
    }
    int mid = (l + r) / 2;
    p->lc = buildTree(l, mid);
    p->rc = buildTree(mid + 1, r);
    p->update();
    return p;
}

// int querymx(Node *x, int l, int r)
// {
//     if (l <= x->l && x->r <= r)
//     {
//         return x->mx;
//     }
//     int res = 0;
//     if (l <= x->lc->r) res = querymx(x->lc, l, r);
//     if (r >= x->rc->l) res = max(res, querymx(x->rc, l, r));
//     return res;
// }

int querynpos(Node *x, int l, int val)
{
    if (l > x->r || x->mx <= val)
        return n + 1;
    if (x->l == x->r)
        return x->l;
    if (l <= x->lc->r)
    {
        int t = querynpos(x->lc, l, val);
        if (t <= n)
            return t;
    }
    return querynpos(x->rc, l, val);
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        a[i] = max(0, i - a[i]);
        prefmx[i] = max(prefmx[i - 1], a[i]);
        sum[i] = sum[i - 1] + prefmx[i];
    }

    {
        stack<int> stk;
        for (int i = n; i >= 1; --i)
        {
            while (!stk.empty() && a[stk.top()] <= a[i])
                stk.pop();
            int npos = stk.empty() ? n + 1 : stk.top();
            suff[i] = suff[npos] + (LL)a[i] * (npos - i);
            stk.push(i);
        }
    }

    root = buildTree(1, n);
    int q;
    cin >> q;
    while (q--)
    {
        int p, x;
        cin >> p >> x;
        x = max(0, p - x);
        x = max(x, prefmx[p - 1]);
        int npos = querynpos(root, p + 1, x);
        LL ans = sum[p - 1] + (LL)x * (npos - p) + suff[npos];
        ans = (LL)n * (n + 1) / 2 - ans;
        cout << ans << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
}