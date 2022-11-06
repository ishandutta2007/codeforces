#include <iostream>
#include <algorithm>

using namespace std;

using LL = long long;

constexpr int MAXN = 100000 + 9;

int n;
LL a[MAXN];

void solve()
{
    LL sum = 0;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        sum += a[i];
    }
    sort(a, a + n, greater<LL>());
    LL t = 2 * a[0] - sum;
    if (t > 0)
    {
        cout << t << '\n';
    }
    else if (sum > 0)
    {
        cout << "1\n";
    }
    else
    {
        cout << "0\n";
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