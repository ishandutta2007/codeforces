#include <iostream>
#include <cstring>

using namespace std;

constexpr int MAXN = 100 + 9;

int n;
char s[MAXN];
bool a[MAXN];

void solve()
{
    memset(a, 0, sizeof(a));
    cin >> n;
    cin >> s;
    for (int i = 0; i < n; ++i)
    {
        a[i] |= s[i] == '0';
    }
    cin >> s;
    for (int i = 0; i < n; ++i)
    {
        a[i] |= s[i] == '0';
    }
    for (int i = 0; i < n; ++i)
    {
        if (!a[i])
        {
            cout << "NO\n";
            return ;
        }
    }
    cout << "YES\n";
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