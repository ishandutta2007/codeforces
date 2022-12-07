#include <bits/stdc++.h>

using namespace std;

using LL = long long;

constexpr int N = 200000 + 9;



void solve()
{
    int n, a, b;
    cin >> n >> a >> b;
    --a; --b;
    vector<vector<pair<int, int>>> e(n);
    vector<int> w1(n), w2(n);
    for (int i = 1; i < n; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }
    set<int> sta, stb;
    function<void(int, int)> dfs1 = [&](int cur, int fa)
    {
        sta.insert(w1[cur]);
        for (auto &[v, w] : e[cur])
        {
            if (v == fa)
                continue;
            if (v == b)
                continue;
            w1[v] = w1[cur] ^ w;
            dfs1(v, cur);
        }
    };
    dfs1(a, -1);
    function<void(int, int)> dfs2 = [&](int cur, int fa)
    {
        if (cur != b)
            stb.insert(w2[cur]);
        for (auto &[v, w] : e[cur])
        {
            if (v == fa)
                continue;
            w2[v] = w2[cur] ^ w;
            dfs2(v, cur);
        }
    };
    dfs2(b, -1);
    for (auto &x : sta)
    {
        if (stb.count(x))
        {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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
}