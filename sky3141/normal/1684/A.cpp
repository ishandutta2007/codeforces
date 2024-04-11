#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

using LL = long long;

constexpr int MAXN = 100000 + 9;

char s[20];

void solve()
{
    cin >> s;
    int n = strlen(s);
    if (n == 2)
    {
        cout << s[1] << '\n';
        return;
    }
    char c = s[0];
    for (int i = 0; i < n; ++i)
    {
        c = min(c, s[i]);
    }
    cout << c << '\n';
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