#include <iostream>
#include <algorithm>

using namespace std;

using LL = long long;

constexpr int MAXN = 5000 + 9, INF = 1000000000;

int n;
int a[MAXN];
int cnt[MAXN];
int f[MAXN];

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        f[i] = -INF;
        fill(cnt + 1, cnt + n + 1, 0);
        int mx = 0;
        for (int j = i - 1; ; )
        {
            if ((j == 0 || a[j] == a[i]) && mx * 2 <= i - j)
                f[i] = max(f[i], f[j] + 1);
            if (j <= 1)
                break;
            ++cnt[a[j]];
            ++cnt[a[j - 1]];
            mx = max(mx, cnt[a[j]]);
            mx = max(mx, cnt[a[j - 1]]);
            j -= 2;
        }
    }
    {
        int i = n + 1;
        f[i] = -INF;
        fill(cnt + 1, cnt + n + 1, 0);
        int mx = 0;
        for (int j = i - 1; ; )
        {
            if (mx * 2 <= i - j)
                f[i] = max(f[i], f[j]);
            if (j <= 1)
                break;
            ++cnt[a[j]];
            ++cnt[a[j - 1]];
            mx = max(mx, cnt[a[j]]);
            mx = max(mx, cnt[a[j - 1]]);
            j -= 2;
        }
    }
    cout << f[n + 1] << '\n';
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