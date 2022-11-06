#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

using LL = long long;

constexpr int MAXN = 100000 + 9;

int n;
int cnt[11][11];

void solve()
{
    memset(cnt, 0, sizeof(cnt));
    char s[3];
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> s;
        ++cnt[s[0] - 'a'][s[1] - 'a'];
    }
    LL ans = 0;
    for (int i = 0; i < 11; ++i)
    {
        LL sum1 = 0, sum2 = 0;
        for (int j = 0; j < 11; ++j)
        {
            ans += sum1 * cnt[i][j];
            sum1 += cnt[i][j];
            ans += sum2 * cnt[j][i];
            sum2 += cnt[j][i];
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
    for (int i = 0; i < T; ++i)
    {
        solve();
    }

    return 0;
}