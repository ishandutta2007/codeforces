#include <cstdio>
#include <cstdint>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <deque>

using namespace std;

#define MAXN 1000010
#define MOD 1000000007
#define F first
#define S second

int inp[MAXN];
int pos[MAXN];
int64_t fac[MAXN];

bool cmp(int a, int b)
{
    return inp[a] < inp[b];
}

int main()
{
    int casN;
    scanf("%d", &casN);
    for (int cas = 0; cas < casN; cas++)
    {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &inp[i]);
            pos[i] = i;
        }
        sort(pos, pos+n, cmp);

        if (n == 1) {printf("1\n"); continue;}

        fac[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            fac[i] = fac[i-1] * i % MOD;
        }

        int l = pos[0];
        int r = pos[1];
        if (l > r) swap(l,r);
        int64_t ans = 1;

        for (int i = 2; i < n; i++)
        {
            if (pos[i] > r)
            {
                r = pos[i];
            }
            else if (pos[i] < l)
            {
                l = pos[i];
            }
            else
            {
                ans = ans * (r - l + 1 - i) % MOD;
            }
        }

        printf("%ld\n", ans);
    }

    return 0;
}