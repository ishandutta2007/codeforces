#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

using LL = long long;

constexpr int MAXN = 200000 + 9;

int n, m;
int a_[MAXN], b_[MAXN];

int& a(int r, int c)
{
    return a_[r * m + c];
}

int& b(int r, int c)
{
    return b_[r * m + c];
}

void solve()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> a(i, j);
            b(i, j) = a(i, j);
        }
        sort(&b(i, 0), &b(i, m));
    }
    int tx = -1, ty = -1;
    vector<int> t;
    for (int i = 0; i < n; ++i)
    {
        int x = -1, y = -1;
        for (int j = 0; j < m; ++j)
        {
            if (a(i, j) != b(i, j))
            {
                if (x == -1)
                {
                    x = j;
                }
                else if (y == -1)
                {
                    y = j;
                }
                else
                {
                    cout << "-1\n";
                    return;
                }
            }
        }
        if (x != -1)
        {
            if (tx == -1)
            {
                tx = x;
                ty = y;
            }
            else
            {
                if (tx != x || ty != y)
                {
                    cout << "-1\n";
                    return;
                }
            }
        }
        else
        {
            t.push_back(i);
        }
    }
    if (tx == -1)
    {
        cout << "1 1\n";
        return;
    }
    for (int i : t)
    {
        if (a(i, tx) != a(i, ty))
        {
            cout << "-1\n";
            return;
        }
    }
    cout << tx + 1 << ' ' << ty + 1 << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }

    return 0;
}