#include <bits/stdc++.h>

using namespace std;

using LL = long long;

constexpr int N = 10000 + 9, K = 6;

int n, m;
vector<int> e[N];
bool dp[1 << K];
bool pre[1 << K];

int cb(int x)
{
    int res = 0;
    while (x)
    {
        res += x & 1;
        x >>= 1;
    }
    return res;
}

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        e[i].clear();
    }
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    vector<int> hcar, ncar;
    int k;

    {
        int f;
        cin >> f;
        vector<int> fs(f);
        for (auto &x : fs)
        {
            cin >> x;
        }
        cin >> k;
        vector<int> nc(k);
        for (auto &p : nc)
        {
            cin >> p;
            --p;
        }
        auto it = nc.begin();
        hcar.reserve(f - k);
        ncar.reserve(k);
        for (int i = 0; i < f; ++i)
        {
            if (it != nc.end() && *it == i)
            {
                ncar.push_back(fs[i]);
                ++it;
            }
            else
            {
                hcar.push_back(fs[i]);
            }
        }
    }

    vector<vector<int>> dis(n + 1);
    auto bfs = [&](int start)
    {
        auto &d = dis[start];
        d = vector<int>(n + 1, n);
        queue<int> que;
        que.push(start);
        d[start] = 0;
        while (!que.empty())
        {
            int cur = que.front();
            que.pop();
            for (auto v : e[cur])
            {
                if (d[v] == n)
                {
                    d[v] = d[cur] + 1;
                    que.push(v);
                }
            }
        }
    };
    bfs(1);
    for (auto x : ncar)
    {
        bfs(x);
    }
    fill(dp, dp + (1 << k), false);
    dp[0] = true;
    for (auto u : hcar)
    {
        copy(dp, dp + (1 << k), pre);
        for (int i = 0; i < (1 << k); ++i)
        {
            vector<int> tmp{1};
            for (int j = 0; j < k; ++j)
            {
                if (i & (1 << j))
                {
                    tmp.push_back(ncar[j]);
                }
            }
            sort(tmp.begin(), tmp.end(), [&dis](int a, int b){ return dis[1][a] < dis[1][b]; });
            tmp.push_back(u);
            int sum = 0;
            for (int i = 0; i + 1 < tmp.size(); ++i)
            {
                sum += dis[tmp[i]][tmp[i + 1]];
            }
            if (sum > dis[1][u])
                continue;
            for (int j = 0; j < (1 << k); ++j)
            {
                dp[j | i] |= pre[j];
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < (1 << k); ++i)
    {
        if (dp[i])
            ans = max(ans, cb(i));
    }
    cout << k - ans << '\n';
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