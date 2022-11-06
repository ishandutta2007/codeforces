#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

using LL = long long;
using pii = pair<int, int>;

constexpr int MAXN = 200000 + 9;

struct Query
{
    int l, r;
    int id;
};

vector<int> factors[MAXN];
LL ans[MAXN];
LL f[MAXN];

inline int lowbit(int x)
{
    return x & (-x);
}

void add(int pos, LL val)
{
    while (pos < MAXN)
    {
        f[pos] += val;
        pos += lowbit(pos);
    }
}

LL query(int pos)
{
    LL res = 0;
    while (pos)
    {
        res += f[pos];
        pos -= lowbit(pos);
    }
    return res;
}

LL querylr(int l, int r)
{
    return query(r) - query(l - 1);
}

void insert(int x)
{
    auto &cur = factors[x];
    for (int i = 0; i + 2 < cur.size(); ++i)
    {
        add(cur[i], cur.size() - i - 2);
    }
}

LL cn3(LL n)
{
    return n * (n - 1) * (n - 2) / 6;
}

LL cntlr(int l, int r, int a, int b)
{
    int mn = (l + a - 1) / a, mx = r / b;
    return mn <= mx ? mx - mn + 1 : 0;
}

void solve()
{
    int n;
    cin >> n;
    vector<Query> q(n);
    for (int i = 0; i < n; ++i)
    {
        auto &[l, r, id] = q[i];
        cin >> l >> r;
        id = i;
    }
    sort(q.begin(), q.end(), [](auto &a, auto &b){ return a.r < b.r; });
    int cur = 0;
    for (auto &[l, r, id] : q)
    {
        while (cur < r)
            insert(++cur);
        LL tans = querylr(l, r) + cntlr(l, r, 3, 6) + cntlr(l, r, 6, 15);
        ans[id] = cn3(r - l + 1) - tans;
    }
    for (int i = 0; i < n; ++i)
    {
        cout << ans[i] << '\n';
    }
}

void init()
{
    for (int i = 1; i < MAXN; ++i)
    {
        for (int j = i; j < MAXN; j += i)
        {
            factors[j].push_back(i);
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    init();
    while (T--)
    {
        solve();
    }

    return 0;
}