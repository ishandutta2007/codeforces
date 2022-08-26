#include <bits/stdc++.h>
#define TASK "a"

typedef long long ll;
typedef long long ull;
typedef long double ld;
typedef std::pair < int , int > ipair;

const int INF = 0x3f3f3f3f;
const int N = 579;
const ll P = 1000000007;

int n, b[N];
ll d[N][N];

ll solve(int l, int r)
{
    if (l == r)
        return 1;
    static bool used[N][N];
    static ll ans[N][N];
    if (used[l][r])
        return ans[l][r];
    used[l][r] = true;

    ++l;
    ++r;
    d[l][0] = 1;
    for (int i = 0; i < r - l; ++i)
    {
        if (d[l][i + 1] != -1)
            continue;
        int c = l + i;
        d[l][i + 1] = 0;
        for (int j = 0; j <= i; ++j)
            if (b[j + l] < b[c + 1])
                (d[l][i + 1] += d[l][j] * solve(j + l, c)) %= P;
    }
    ll res = 0;
    for (int j = 0; j <= r - l - 1; ++j)
        (res += d[l][j] * solve(j + l, r - 1)) %= P;
    --l;
    --r;
    return ans[l][r] = res;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    memset(d, -1, sizeof(d));
    std::cin >> n;
    for (int i = 0; i < n; ++i)
        std::cin >> b[i];
    if (b[0] == 1)
        std::cout << solve(0, n - 1) << "\n";
    else
        std::cout << 0 << "\n";
    return 0;
}