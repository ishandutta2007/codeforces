#include <bits/stdc++.h>
#define TASK "a"

typedef long long ll;
typedef long long ull;
typedef long double ld;
typedef std::pair < int , int > ipair;

const int INF = 0x3f3f3f3f;
const int N = 179;

int n, k, a[N];
int mn = INF, mx = -INF;

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    std::cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> a[i];
        mn = std::min(a[i], mn);
        mx = std::max(a[i], mx);
    }

    for (int i = 0; i <= mn; ++i)
    {
        if (k < mx - i)
            continue;
        else
        {
            std::cout << "YES\n";
            for (int j = 0; j < n; ++j)
            {
                for (int q = 0; q < i; ++q)
                    std::cout << "1 ";
                for (int q = 0; q < a[j] - i; ++q)
                    std::cout << q + 1 << " ";
                std::cout << "\n";
            }
            return 0;
        }
    }
    std::cout << "NO\n";

    return 0;
}