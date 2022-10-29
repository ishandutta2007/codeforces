#include <iostream>
#include <cstdio>
#include <cassert>
#include <algorithm>
#include <vector>

using namespace std;

#ifdef _DEBUG
#define endline endl
#else
#define endline "\n"
#endif

#define pb push_back

#define MAXN 550000
#define MAXK 1500000

typedef vector < int > vi;

struct List
{
    int setI;
    int maxI;
    bool set;
    int get() const
    {
        return (set) ? max(maxI, setI) : maxI;
    }
    void upd(const List &a, const List &b)
    {
        set = false;
        setI = 0;
        maxI = max(a.get(), b.get());
    }
} tree[MAXK];

int n, q;
int mtree[MAXK];
int curk;
int lft[MAXN], rght[MAXN];
vector < vi > g;
vector < bool > used;
static int timer = 1;

void update_r(const int l, const int r, const int l1, const int r1, const int v, const int x)
{
#ifdef _DEBUG
    cerr << "upd [" << l << "; " << r << "] -> [" << l1 << "; " << r1 << "] in " << v << endline;
#endif
    if (max(l, l1) <= min(r , r1))
    {
        if (l <= l1 && r >= r1)
        {
            tree[v].set = true;
            tree[v].setI = x;
#ifdef _DEBUG
        cerr << "tree[" << v << "].max = " << tree[v].get() << endline;
        cerr << tree[v].maxI << " " << tree[v].setI << endline;
#endif
            return;
        }
        tree[v * 2].set = tree[v * 2 + 1].set = true;
        tree[v * 2].setI = max(tree[v * 2].setI, tree[v].setI);
        tree[v * 2 + 1].setI = max(tree[v * 2 + 1].setI, tree[v].setI);
        int m1 = (l1 + r1) / 2;
        update_r(l, r, l1, m1, v * 2, x);
        update_r(l, r, m1 + 1, r1, v * 2 + 1, x);
        tree[v].upd(tree[v * 2], tree[v * 2 + 1]);
#ifdef _DEBUG
        cerr << "tree[" << v << "].max = " << tree[v].get() << endline;
        cerr << tree[v].maxI << " " << tree[v].setI << endline;
#endif
    }
}

int getMax_r(const int l, const int r, const int l1, const int r1, const int v)
{
    int res = -1;
    if (max(l, l1) <= min(r, r1))
    {
#ifdef _DEBUG
        cerr << "tree[" << v << "].max = " << tree[v].get() << endline;
        cerr << tree[v].maxI << " " << tree[v].setI << endline;
#endif
        if (l <= l1 && r >= r1)
        {
            return tree[v].get();
        }
        tree[v * 2].set = tree[v * 2 + 1].set = true;
        tree[v * 2].setI = max(tree[v * 2].setI, tree[v].setI);
        tree[v * 2 + 1].setI = max(tree[v * 2 + 1].setI, tree[v].setI);
        int m1 = (l1 + r1) / 2;
        int l_a = getMax_r(l, r, l1, m1, v * 2);
        int r_a = getMax_r(l, r, m1 + 1, r1, v * 2 + 1);
        res = max(res, max(l_a, r_a));
        tree[v].upd(tree[v * 2], tree[v * 2 + 1]);
#ifdef _DEBUG
    cerr << "get [" << l << "; " << r << "] -> [" << l1 << "; " << r1 << "] = " << res << endline;
#endif
    }
    return res;
}

void upd_s(const int pos, const int val)
{
    mtree[pos + curk - 1] = val;
    int par = (pos + curk - 1) / 2;
    while (par != 0)
    {
        mtree[par] = max(mtree[par * 2], mtree[par * 2 + 1]);
        par /= 2;
    }
}

int max_s(int l, int r)
{
    int res = 0;
    l += curk - 1, r += curk - 1;
    while (l < r)
    {
        res = max(max(mtree[l], mtree[r]), res);
        l = (l + 1) / 2;
        r = (r - 1) / 2;
    }
    if (l == r)
    {
        res = max(res, mtree[l]);
    }
    return res;
}

void init()
{
    curk = 2;
    while (curk < n)
    {
        curk *= 2;
    }
    for (int i = 0; i < 2 * curk; ++i)
    {
        tree[i].set = false;
        tree[i].setI = 0;
        tree[i].maxI = 0;
    }
    for (int i = 0; i < 2 * curk; ++i)
    {
        mtree[i] = 0;
    }
}

void dfs(const int x)
{
    lft[x] = timer++;
    used[x] = true;
    for (vi::iterator it = g[x].begin(); it != g[x].end(); ++it)
    {
        if (!used[*it])
        {
            dfs(*it);
        }
    }
    rght[x] = timer - 1;
}

int
main()
{
    scanf("%d", &n);
    g.resize(n + 1);
    used.resize(n + 1);
    for (int i = 0; i < n - 1; ++i)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        g[a].pb(b);
        g[b].pb(a);
    }
    timer = 1;
    dfs(1);
    init();
#ifdef _DEBUG
    for (int i = 1; i <= n; ++i)
    {
        cerr << i << ": [" << lft[i] << "; " << rght[i] << "]" << endline;
    }
#endif
    scanf("%d", &q);
    for (int i = 0; i < q; ++i)
    {
        int tp, v;
        scanf("%d%d", &tp, &v);
#ifdef _DEBUG
        cerr << "tp = " << tp << " v = " << v << endline;
#endif       
        if (tp == 1)
        {
            update_r(lft[v], rght[v], 1, curk, 1, i + 1);
        }
        else if (tp == 2)
        {
            upd_s(lft[v], i + 1);
        }
        else
        {
#ifdef _DEBUG
            assert(tp == 3);
#endif
            int sleeve = getMax_r(lft[v], lft[v], 1, curk, 1);
            int recover = max_s(lft[v], rght[v]);
#ifdef _DEBUG
            cerr << "add " << sleeve << " pop " << recover << endline;
#endif
            if (sleeve > recover)
            {
                printf("1\n");
            }
            else
            {
                printf("0\n");
            }
        }
#ifdef _DEBUG
        cerr << "control" << endline;
        for (int i = 1; i <= n; ++i)
        {
            cerr << "level[" << i << "] = " << getMax_r(lft[v], lft[v], 1, curk, 1) << endline;
        }
#endif
    }
    return 0;
}