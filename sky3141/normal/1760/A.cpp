#include <bits/stdc++.h>

using namespace std;

using LL = long long;

constexpr int N = 200000 + 9;



void solve()
{
    int a[3];
    for (int i = 0; i < 3; ++i)
    {
        cin >> a[i];
    }
    sort(a, a + 3);
    cout << a[1] << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
}