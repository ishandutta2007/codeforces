#include <bits/stdc++.h>

using namespace std;

using LL = long long;



void solve()
{
    int n;
    cin >> n;
    int cnt[10]{};
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        ++cnt[x % 10];
    }
    for (int i = 0; i < 10; ++i)
    {
        for (int j = i; j < 10; ++j)
        {
            for (int k = j; k < 10; ++k)
            {
                --cnt[i]; --cnt[j]; --cnt[k];
                if (cnt[i] >= 0 && cnt[j] >= 0 && cnt[k] >= 0 && (i + j + k) % 10 == 3)
                {
                    cout << "yes\n";
                    return;
                }
                ++cnt[i]; ++cnt[j]; ++cnt[k];   
            }
        }
    }
    cout << "no\n";
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