#include <iostream>

using namespace std;


void solve()
{
    int n, l;
    int cnt[32] = {};
    cin >> n >> l;
    for (int i = 0; i < n; ++i)
    {
        int tmp;
        cin >> tmp;
        for (int j = 0; j < l; ++j)
        {
            if (tmp & (1 << j))
                ++cnt[j];
        }
    }
    int ans = 0;
    for (int i = 0; i < l; ++i)
    {
        if (cnt[i] > (n / 2))
            ans |= 1 << i;
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