#include <iostream>

using namespace std;

constexpr int MAXN = 50 + 9;

void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int cur = n, first = n - i - 1, second = i;
        for (int j = 0; j < first; ++j)
            cout << cur-- << ' ';
        cout << "1 ";
        for (int j = 0; j < second; ++j)
        {
            cout << cur-- << ' ';
        }
        cout << '\n';
    }
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