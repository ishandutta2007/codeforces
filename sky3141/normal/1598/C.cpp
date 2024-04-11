#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

using LL = long long;

constexpr int MAXN = 200000 + 9;

int n;
int a[MAXN];

void solve()
{
    LL sum = 0;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        sum += a[i];
    }
    sum *= 2;
    if (sum % n != 0)
    {
        cout << "0\n";
        return ;
    }
    int tgt = sum / n;
    sort(a, a + n);
    int l = 0, r = n - 1;
    LL ans = 0;
    while (l <= r)
    {
        if (a[l] + a[r] < tgt)
        {
            ++l;
            continue;
        }
        if (a[l] + a[r] > tgt)
        {
            --r;
            continue;
        }
        int t1 = a[l], t2 = a[r];
        LL cnt1 = 0, cnt2 = 0;
        while (l < n && a[l] == t1)
        {
            ++l;
            ++cnt1;
        }
        while (r >= 0 && a[r] == t2)
        {
            --r;
            ++cnt2;
        }
        if (t1 != t2)
            ans += cnt1 * cnt2;
        else
            ans += cnt1 * (cnt1 - 1) / 2;
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