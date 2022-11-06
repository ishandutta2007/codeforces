#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <set>
#include <map>
#include <queue>
#include <string>

using namespace std;

using LL = long long;

constexpr int MAXW = 1000 + 9;

struct Query
{
    int h, w;
    int id;
    int k;
};

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<array<int, 2>> a(n);
    for (auto &[h, w] : a)
    {
        cin >> h >> w;
    }
    vector<Query> qry;
    for (int i = 0; i < q; ++i)
    {
        int h1, w1, h2, w2;
        cin >> h1 >> w1 >> h2 >> w2;
        --h2; --w2;
        qry.push_back({h1, w1, i, 1});
        qry.push_back({h1, w2, i, -1});
        qry.push_back({h2, w1, i, -1});
        qry.push_back({h2, w2, i, 1});
    }
    vector<LL> ans(q);
    vector<LL> f(MAXW);
    auto lowbit = [](int x){ return x & -x; };
    auto add = [&f, &lowbit](int pos, LL val)
    {
        while (pos < MAXW)
        {
            f[pos] += val;
            pos += lowbit(pos);
        }
    };
    auto query = [&f, &lowbit](int pos)
    {
        LL res = 0;
        while (pos)
        {
            res += f[pos];
            pos -= lowbit(pos);
        }
        return res;
    };
    sort(qry.begin(), qry.end(), [](auto &a, auto &b){ return a.h < b.h; });
    sort(a.begin(), a.end(), [](auto &a, auto &b){ return a[0] < b[0]; });
    auto it = a.begin();
    for (auto &[h, w, id, k] : qry)
    {
        while (it != a.end() && (*it)[0] <= h)
        {
            add((*it)[1], (*it)[0] * (*it)[1]);
            ++it;
        }
        ans[id] += k * query(w);
    }
    for (auto &x : ans)
    {
        cout << x << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    
    return 0;
}