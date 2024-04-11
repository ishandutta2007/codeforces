#include <bits/stdc++.h>
typedef long long ll;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    int t; std::cin >> t;
    while (t--)
    {
        int n; std::cin >> n;
        std::vector < int > a(n + 1);
        for (int i = 1; i <= n; ++i)
            std::cin >> a[i];
        std::vector < int > vis(n + 1, 0);
        int pos = n, last = n;
        for (int i = n; i >= 1; --i)
        {
            if (a[i] != pos) continue;
            else
            {
                for (int j = i; j <= last; ++j)
                {
                    std::cout << a[j] << ' ';
                    vis[a[j]] = 1;
                }
                while (vis[pos] == 1) --pos;
                last = i - 1;
            }
        }
        std::cout << std::endl;
    }
    return 0;
}