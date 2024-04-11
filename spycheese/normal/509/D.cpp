#include <bits/stdc++.h>
#define TASK "a"

typedef long long ll;
typedef long long ull;
typedef long double ld;
typedef std::pair < int , int > ipair;

const int INF = 0x3f3f3f3f;
const int N = 179;

int n, m;
ll w[N][N];
ll k, a[N], b[N];

void fail()
{
    std::cout << "NO\n";
    exit(0);
}

void check()
{
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (w[i][j] != (a[i] + b[j]) % k)
                fail();
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    std::cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            std::cin >> w[i][j];
    memset(b, -1, sizeof(b));
    b[0] = 0;
    k = -1;
    for (int i = 0; i < n; ++i)
        a[i] = w[i][0];
    for (int j = 1; j < m; ++j)
    {
        ll op = -1, on = 1;
        for (int i = 0; i < n; ++i)
        {
            ll oo = w[i][j] - a[i];
            if (oo >= 0)
            {
                if (op != -1 && op != oo)
                    fail();
                op = oo;
            } else {
                if (on != 1 && on != oo)
                    fail();
                on = oo;
            }
        }
        if (op != -1 && on != 1)
        {
            ll nk = op - on;
            if (k != -1 && k != nk)
                fail();
            k = nk;
            b[j] = op;
        } else if (op != -1)
            b[j] = op;
        else if (k != -1)
            b[j] = k + on;
    }

    if (k == -1)
        k = 1000000007;
    for (int i = 0; i < m; ++i)
        if (b[i] == -1)
            b[i] = (w[0][i] - a[0] + k) % k;

    check();
    std::cout << "YES\n" << k << "\n";
    for (int i = 0; i < n; ++i)
        std::cout << a[i] << " ";
    std::cout << "\n";
    for (int i = 0; i < m; ++i)
        std::cout << b[i] << " ";
    std::cout << "\n";

    return 0;
}