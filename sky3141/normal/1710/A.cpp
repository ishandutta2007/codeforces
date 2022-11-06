#include <iostream>
#include <algorithm>

using namespace std;

using LL = long long;

constexpr int MAXN = 100000 + 9;

int n, m;
int k;
int a[MAXN];

void solve()
{
    cin >> n >> m >> k;
    for (int i = 0; i < k; ++i)
    {
        cin >> a[i];
    }
    LL sum = 0;
    bool flag = false;
    for (int i = 0; i < k; ++i)
    {
        int tmp = a[i] / n;
        if (tmp >= 2)
        {
            sum += tmp;
        }
        if (tmp >= 3)
        {
            flag = true;
        }
    }
    if (sum >= m && !(m % 2 == 1 && !flag))
    {
        cout << "Yes\n";
        return;
    }
    sum = 0;
    flag = false;
    for (int i = 0; i < k; ++i)
    {
        int tmp = a[i] / m;
        if (tmp >= 2)
        {
            sum += tmp;
        }
        if (tmp >= 3)
        {
            flag = true;
        }
    }
    if (sum >= n && !(n % 2 == 1 && !flag))
    {
        cout << "Yes\n";
        return;
    }
    cout << "No\n";
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