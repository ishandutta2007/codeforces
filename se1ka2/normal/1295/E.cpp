#include <iostream>
#include <cassert>
#include <vector>
using namespace std;
typedef long long ll;

const ll INF = 100000000000000000;

template <typename S,
          S (*op)(S, S),
          S (*e)(),
          typename F,
          S (*mapping)(F, S),
          F (*composition)(F, F),
          F (*id)()>
struct LazySegmentTree
{
    int n;
    std::vector<S> dat;
    std::vector<F> lazy;

    LazySegmentTree()
    {
    }

    LazySegmentTree(int _n)
    {
        n = 1;
        while (n <= _n)
        {
            n <<= 1;
        }
        dat.assign(n * 2, e());
        lazy.assign(n * 2, id());
    }

    void set(int i, S x)
    {
        dat[i + n] = x;
    }

    void build()
    {
        for (int k = n - 1; k > 0; k--)
        {
            dat[k] = op(dat[k * 2], dat[k * 2 + 1]);
        }
    }

    void eval(int k)
    {
        dat[k] = mapping(lazy[k], dat[k]);
        if (k < n)
        {
            lazy[k * 2] = composition(lazy[k], lazy[k * 2]);
            lazy[k * 2 + 1] = composition(lazy[k], lazy[k * 2 + 1]);
        }
        lazy[k] = id();
    }

    void update(int l, int r, int a, int b, int k, F f)
    {
        eval(k);
        if (l >= b || r <= a)
        {
            return;
        }
        if (l <= a && r >= b)
        {
            lazy[k] = f;
            eval(k);
        }
        else
        {
            update(l, r, a, (a + b) / 2, k * 2, f);
            update(l, r, (a + b) / 2, b, k * 2 + 1, f);
            dat[k] = op(dat[k * 2], dat[k * 2 + 1]);
        }
    }

    void update(int l, int r, F f)
    {
        update(l, r, 0, n, 1, f);
    }

    S query(int l, int r, int a, int b, int k)
    {
        eval(k);
        if (l >= b || r <= a)
        {
            return e();
        }
        if (l <= a && r >= b)
        {
            return dat[k];
        }
        return op(query(l, r, a, (a + b) / 2, k * 2), query(l, r, (a + b) / 2, b, k * 2 + 1));
    }

    S query(int l, int r)
    {
        return query(l, r, 0, n, 1);
    }

    S operator[](int i)
    {
        return query(i, i + 1);
    }
};

struct S
{
    ll a;
    int i;

    bool operator<(const S& r) const
    {
        if(a != r.a)
        {
            return a < r.a;
        }
        return i > r.i;
    }
};

S op(S a, S b)
{
    return min(a, b);
}

S e()
{
    return S{INF, -1};
}

using F = ll;

S mapping(F f, S a)
{
    return S{a.a + f, a.i};
}

F composition(F f, F g)
{
    return f + g;
}

F id()
{
    return 0;
}

int main()
{
    int n;
    cin >> n;
    int p[200005];
    int q[200005];
    for(int i = 0; i < n; i++)
    {
        cin >> p[i];
        p[i]--;
        q[p[i]] = i;
    }
    ll a[200005];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    LazySegmentTree<S, op, e, F, mapping, composition, id> seg(n + 1);
    ll s = 0;
    ll t = 0;
    seg.set(0, S{s, 0});
    for(int i = 1; i <= n; i++)
    {
        if(p[i - 1] < p[0])
        {
            s -= a[i - 1];
            t += a[i - 1];
        }
        else
        {
            s += a[i - 1];
        }
        seg.set(i, S{s, i});
    }
    seg.build();
    ll ans = a[0];
    int l = 0;
    for(int u = p[0]; u < n; u++)
    {
        int i = q[u];
        if(i < l)
        {
            t -= a[i];
        }
        else
        {
            t += a[i];
            seg.update(i + 1, n + 1, -a[i] * 2);
        }
        S s = seg.query(l, n);
        t += s.a;
        ans = min(ans, t);
        l = s.i;
        seg.update(l, n + 1, -s.a);
    }
    cout << ans << endl;
}