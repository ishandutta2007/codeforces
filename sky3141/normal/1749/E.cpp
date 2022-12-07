#include <bits/stdc++.h>

using namespace std;

using LL = long long;

constexpr int N = 200000 + 9, NM = 400000 + 9;
constexpr int pathadj[4][2]{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
constexpr int pathdiag[4][2]{{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

int n, m;
char a_[NM];
char ans_[NM];
int pre_[NM];

inline int idx(int r, int c)
{
    return r * m + c;
}

inline pair<int, int> pos(int index)
{
    return {index / m, index % m};
}

inline char& a(int r, int c)
{
    return a_[idx(r, c)];
}

inline char& ans(int r, int c)
{
    return ans_[idx(r, c)];
}

inline int& pre(int r, int c)
{
    return pre_[idx(r, c)];
}

inline bool inmap(int r, int c)
{
    return r >= 0 && r < n && c >= 0 && c < m;
}

void solve()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> a(i, j);
            ans(i, j) = a(i, j);
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (a(i, j) == '#')
            {
                for (auto [dr, dc] : pathadj)
                {
                    int nr = i + dr, nc = j + dc;
                    if (inmap(nr, nc))
                    {
                        a(nr, nc) = 'x';
                    }
                }
            }
        }
    }
    deque<int> que;
    auto push = [&](int r, int c)
    {
        if (a(r, c) == '.')
            que.push_back(idx(r, c));
        else
            que.push_front(idx(r, c));
        a(r, c) = 'v';
    };
    for (int i = 0; i < n; ++i)
    {
        if (a(i, 0) != 'x')
        {
            pre(i, 0) = -1;
            push(i, 0);
        }
    }
    int aid = -1;
    while (!que.empty())
    {
        auto [r, c] = pos(que.front());
        que.pop_front();
        if (c == m - 1)
        {
            aid = idx(r, c);
            break;
        }
        for (auto [dr, dc] : pathdiag)
        {
            int nr = r + dr, nc = c + dc;
            if (inmap(nr, nc) && (a(nr, nc) == '.' || a(nr, nc) == '#'))
            {
                pre(nr, nc) = idx(r, c);
                push(nr, nc);
            }
        }
    }
    if (aid == -1)
    {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    while (aid != -1)
    {
        ans_[aid] = '#';
        aid = pre_[aid];
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cout << ans(i, j);
        }
        cout << '\n';
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
}