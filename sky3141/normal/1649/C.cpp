#include <iostream>
#include <algorithm>

using namespace std;

using LL = long long;

constexpr int MAXN = 100000 + 9;

int n, m;
int aa[MAXN];
LL cnt[MAXN];
LL s[MAXN];

int& a(int x, int y)
{
    return aa[x * m + y];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> a(i, j);
        }
    }
    LL ans = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            int c = a(i, j);
            ans += cnt[c] * i - s[c];
            ++cnt[c];
            s[c] += i;
        }
    }
    fill(cnt, cnt + MAXN, 0);
    fill(s, s + MAXN, 0);
    for (int j = 0; j < m; ++j)
    {
        for (int i = 0; i < n; ++i)
        {
            int c = a(i, j);
            ans += cnt[c] * j - s[c];
            ++cnt[c];
            s[c] += j;
        }
    }
    cout << ans << '\n';

    return 0;
}