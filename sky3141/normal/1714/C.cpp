#include <bits/stdc++.h>

using namespace std;

using LL = long long;

constexpr int MAXN = 200000 + 9;

int s;
int sum;
int tt;
int a[100];

bool dfs(int step, int cur)
{
    if (step == tt)
    {
        if (sum == s)
        {
            for (int i = 0; i < step; ++i)
            {
                cout << a[i];
            }
            cout << '\n';
            return true;
        }
        return false;
    }
    for (int i = cur + 1; i <= 9; ++i)
    {
        sum += i;
        a[step] = i;
        if (dfs(step + 1, i))
            return true;
        sum -= i;
    }
    return false;
}

void solve()
{
    cin >> s;
    for (int i = 1; i <= 9; ++i)
    {
        sum = 0;
        tt = i;
        if (dfs(0, 0))
            return;
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