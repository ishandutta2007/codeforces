#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

using LL = long long;

constexpr int MAXN = 200000 + 9;

struct Node
{
    int l, r;
    LL mx;
    Node *lc, *rc;

    void update()
    {
        mx = max(lc->mx, rc->mx);
    }
} pool[MAXN * 2 * 2], *alloc;

Node* buildTree(int l, int r, const vector<LL> &val)
{
    Node *p = ++alloc;
    p->l = l;
    p->r = r;
    if (l == r)
    {
        p->mx = val[l];
        p->lc = p->rc = nullptr;
        return p;
    }
    int mid = (l + r) / 2;
    p->lc = buildTree(l, mid, val);
    p->rc = buildTree(mid + 1, r, val);
    p->update();
    return p;
}

void change(Node *x, int pos, LL delta)
{
    if (x->l == x->r)
    {
        x->mx += delta;
        return;
    }
    if (pos <= x->lc->r) change(x->lc, pos, delta);
    else change(x->rc, pos, delta);
    x->update();
}

LL calcans(const vector<Node*> &root)
{
    LL res = 0;
    for (auto &rt : root)
    {
        res = max(res, rt->mx);
    }
    return res;
}

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto &x : a)
    {
        cin >> x;
    }
    vector<int> pds;
    for (int i = 2; i <= n; ++i)
    {
        if (n % i == 0)
        {
            for (auto &p : pds)
            {
                if (i % p == 0)
                    goto continue_loop;
            }
            pds.push_back(i);
        }
        continue_loop:;
    }
    alloc = pool;
    int pn = pds.size();
    vector<Node*> root;
    root.reserve(pn);
    for (auto &p : pds)
    {
        int len = n / p;
        vector<LL> val(len);
        for (int i = 0; i < len; ++i)
        {
            LL sum = 0;
            for (int j = i; j < n; j += len)
            {
                sum += a[j];
            }
            val[i] = sum * len;
        }
        root.push_back(buildTree(0, len - 1, val));
    }
    cout << calcans(root) << '\n';
    for (int tq = 0; tq < q; ++tq)
    {
        int pos, val;
        cin >> pos >> val;
        --pos;
        LL delta = val - a[pos];
        a[pos] = val;
        for (int i = 0; i < pn; ++i)
        {
            int len = n / pds[i];
            change(root[i], pos % len, delta * len);
        }
        cout << calcans(root) << '\n';
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }

    return 0;
}