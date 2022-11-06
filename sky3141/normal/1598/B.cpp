#include <iostream>
#include <cstring>

using namespace std;

using u8 = unsigned char;

constexpr int MAXN = 100000 + 9;

int n;
u8 a[MAXN];

void solve()
{
    memset(a, 0, sizeof(a));
    cin >> n;
    int half = n >> 1;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            int t;
            cin >> t;
            a[i] |= t << j;
        }
    }
    for (int i = 0; i < 5; ++i)
    {
        for (int j = i + 1; j < 5; ++j)
        {
            int x = 0, y = 0, z = 0;
            for (int k = 0; k < n; ++k)
            {
                bool t1 = a[k] & (1 << i), t2 = a[k] & (1 << j);
                if (t1 && t2)
                    ++z;
                else if (t1)
                    ++x;
                else if (t2)
                    ++y;
            }
            if (x < half)
                z -= half - x;
            if (y < half)
                z -= half - y;
            if (z >= 0)
            {
                cout << "YES\n";
                return ;
            }
        }
    }
    cout << "NO\n";
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