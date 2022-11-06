#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

using LL = long long;

constexpr int MAXN = 100000 + 9;

int n;
int a[MAXN];

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        a[i] = i;
    }
    for (int i = n - 1; i >= 1; i -= 2)
    {
        swap(a[i], a[i + 1]);
    }
    for (int i = 1; i <= n; ++i)
    {
        cout << a[i] << ' ';
    }
    cout << '\n';
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }

    return 0;
}