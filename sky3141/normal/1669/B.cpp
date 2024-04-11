#include <iostream>
#include <algorithm>

using namespace std;

constexpr int MAXN = 200000 + 9;

int n;
int a[MAXN];

void solve()
{
    cin >> n;
    fill(a, a + n + 1, 0);
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        ++a[x];
    }
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] >= 3)
        {
            cout << i << '\n';
            return;
        }
    }
    cout << "-1\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for (int i = 0; i < T; ++i)
    {
        solve();
    }

    return 0;
}