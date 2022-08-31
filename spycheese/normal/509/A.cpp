#include <bits/stdc++.h>
#define TASK "a"

typedef long long ll;
typedef long long ull;
typedef long double ld;
typedef std::pair < int , int > ipair;

const int INF = 0x3f3f3f3f;
const int N = 100;

ull a[N][N];

int main()
{
#ifdef LOCAL
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
        {
            if (i * j == 0)
                a[i][j] = 1;
            else
                a[i][j] = a[i - 1][j] + a[i][j - 1];
        }

    std::cout << a[n - 1][n - 1] << "\n";

    return 0;
}