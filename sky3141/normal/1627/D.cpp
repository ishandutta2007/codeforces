#include <iostream>
#include <bitset>

using namespace std;

constexpr int MAXN = 1000000 + 9;

int n;
bitset<MAXN> num;

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int cur;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> cur;
        num.set(cur);
    }
    int ans = 0;
    for (int i = MAXN - 1; i > 0; --i)
    {
        if (!num[i])
        {
            int g = 0;
            for (int j = 2; i * j < MAXN; ++j)
            {
                if (num[i * j])
                {
                    g = gcd(j, g);
                }
            }
            if (g == 1)
            {
                num.set(i);
                ++ans;
            }
        }
    }
    cout << ans << '\n';

    return 0;
}