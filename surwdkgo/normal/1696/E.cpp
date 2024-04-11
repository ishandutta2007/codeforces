#include <cstdio>
#include <cstdint>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <deque>

using namespace std;

#define MAXN 1000010
#define F first
#define S second
#define MOD 1000000007

int64_t pow_x(int64_t x, int64_t v)
{
    if (v == 0) return 1;
    if (v == 1) return x % MOD;

    int64_t sub = pow_x(x, v/2);
    int64_t ans = sub * sub % MOD;
    return v%2 == 0 ? ans : ans * x % MOD;
}

int64_t inv(int64_t x)
{
    return pow_x(x, MOD-2);
}

int main()
{
    int casN = 1;
    //scanf("%d", &casN);
    for (int cas = 0; cas < casN; cas++)
    {
        int n;
        scanf("%d", &n);
        int inp;

        int64_t cur = 1;
        int64_t ans = 0;

        int t_bg = 1, t_ed = 1;

        for (int i =0 ; i<=n; i++)
        {
            scanf("%d", &inp);

            if (inp == 0) continue;

            while (t_ed <= inp + i)
            {
                cur = cur * t_ed % MOD;
                t_ed++;
            }

            while (t_ed > inp + i + 1)
            {
                cur = cur * inv(t_ed-1) % MOD;
                t_ed--;
            }

            while (t_bg < inp)
            {
                cur = cur * inv(t_bg) % MOD;
                t_bg++;
            }

            while (t_bg > inp)
            {
                cur = cur * (t_bg - 1) % MOD;
                t_bg--;
            }

            cur = cur * inv(i+1) % MOD;

            ans = (ans + cur) % MOD;
        }

        printf("%d\n", ans);
    }

    return 0;
}