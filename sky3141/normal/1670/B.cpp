#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

using LL = long long;

constexpr int MAXN = 100000 + 9;

int n, k;
char s[MAXN];
bool special[256];

void solve()
{
    cin >> n;
    cin >> s;
    cin >> k;
    memset(special, 0, sizeof(special));
    for (int i = 0; i < k; ++i)
    {
        char c;
        cin >> c;
        special[c] = true;
    }
    int l = 0, ans = 0;
    for (int i = 1; i < n; ++i)
    {
        if (special[s[i]])
        {
            ans = max(ans, i - l);
            l = i;
        }
    }
    cout << ans << '\n';
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