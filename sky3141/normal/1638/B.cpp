#include <iostream>
#include <algorithm>

using namespace std;

// constexpr int MAXN = 100000 + 9;

int n;
// int a[MAXN];

void solve()
{
    cin >> n;
    int odd = 0, even = 0, cur;
    bool flag = true;
    for (int i = 0; i < n; ++i)
    {
        cin >> cur;
        if (cur & 1)
        {
            if (cur < odd)
                flag = false;
            odd = cur;
        }
        else
        {
            if (cur < even)
                flag = false;
            even = cur;
        }
    }
    cout << (flag ? "Yes\n" : "No\n");
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