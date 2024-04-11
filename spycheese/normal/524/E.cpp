#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair < int , int > pair;

const int IINF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const double DINF = std::numeric_limits<double>::infinity();
const double EPS = 1e-8;

const int N = 1 << 17;

int tree[N * 2 - 1];

void treeInit()
{
    memset(tree, -1, sizeof(tree));
}

void treeSet(int c, int x)
{
    c += N - 1;
    tree[c] = x;
    while (c != 0)
    {
        (--c) >>= 1;
        tree[c] = std::min(tree[c * 2 + 1], tree[c * 2 + 2]);
    }
}

int treeGetMin(int l, int r, int c = 0, int cl = 0, int cr = N - 1)
{
    if (cl > r || cr < l)
        return IINF;
    if (l <= cl && cr <= r)
        return tree[c];
    return std::min(treeGetMin(l, r, c*2+1, cl, (cl+cr) / 2),
                    treeGetMin(l, r, c*2+2, (cl+cr) / 2 + 1, cr));
}

struct Rect
{
    ll x1, y1, x2, y2;
    bool okX, okY;
};

int n, m;
int k, q;
int x[N * 2], y[N * 2];
Rect r[N * 2];

void swapAll()
{
    std::swap(n, m);
    for (int i = 0; i < k; ++i)
        std::swap(x[i], y[i]);
    for (int i = 0; i < q; ++i)
    {
        std::swap(r[i].x1, r[i].y1);
        std::swap(r[i].x2, r[i].y2);
        std::swap(r[i].okX, r[i].okY);
    }
}

void solve()
{
    struct Event
    {
        bool rock;
        int x;
        union
        {
            int y;
            struct { int y1, y2, num; };
        };

        bool operator < (const Event & b) const
        {
            if (x == b.x)
                return rock > b.rock;
            return x < b.x;
        }
    };
    static Event e[N * 4];
    int ec = 0;

    for (int i = 0; i < k; ++i)
    {
        e[ec].x = x[i];
        e[ec].y = y[i];
        e[ec].rock = true;
        ++ec;
    }
    for (int i = 0; i < q; ++i)
    {
        e[ec].x = r[i].x2;
        e[ec].y1 = r[i].y1;
        e[ec].y2 = r[i].y2;
        e[ec].num = i;
        e[ec].rock = false;
        ++ec;
    }
    std::sort(e, e + ec);

    treeInit();
    for (int i = 0; i < ec; ++i)
        if (e[i].rock)
            treeSet(e[i].y, e[i].x);
        else
        {
            Rect & cr = r[e[i].num];
            cr.okX = (treeGetMin(e[i].y1, e[i].y2) >= cr.x1);
        }
}

int main()
{
    std::ios::sync_with_stdio(false);

    std::cin >> n >> m >> k >> q;
    for (int i = 0; i < k; ++i)
    {
        std::cin >> x[i] >> y[i];
        --x[i];
        --y[i];
    }
    for (int i = 0; i < q; ++i)
    {
        std::cin >> r[i].x1 >> r[i].y1 >> r[i].x2 >> r[i].y2;
        --r[i].x1; --r[i].y1; --r[i].x2; --r[i].y2;
    }

    solve();
    swapAll();
    solve();

    for (int i = 0; i < q; ++i)
        if (r[i].okX || r[i].okY)
            std::cout << "YES\n";
        else
            std::cout << "NO\n";
    return 0;
}