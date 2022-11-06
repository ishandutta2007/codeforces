#include <bits/stdc++.h>

using namespace std;

using LL = long long;

constexpr int MAXN = 200000 + 9;



void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    int k = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> b[i];
        if (b[i] > i)
            k = max(k, i);
        // else
        //     maxk = min(maxk, i - 1);
    }
    cout << k << '\n';
    vector<int> d(n + 1), ind(n + 1);
    vector<vector<int>> nxt(n + 1);
    vector<int> ans;
    priority_queue<pair<int, int>> que;
    for (int i = 1; i <= n; ++i)
    {
        if (b[i] != 0 && b[i] != n + 1)
        {
            nxt[b[i]].push_back(i);
            ++d[i];
            ++ind[b[i]];
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (b[i] == 0 || b[i] == n + 1)
        {
            if (ind[i])
                que.push({0, i});
            else
                que.push({1, i});
        }
    }
    while (!que.empty())
    {
        int cur = que.top().second;
        que.pop();
        ans.push_back(cur);
        for (auto v : nxt[cur])
        {
            --d[v];
            if (d[v] == 0)
            {
                if (ind[v])
                    que.push({0, v});
                else
                    que.push({1, v});
            }
        }
    }
    for (auto x : ans)
    {
        cout << x << ' ';
    }
    cout << '\n';
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