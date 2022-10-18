#include <cstdio>
#include <cstdint>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <cinttypes>

using namespace std;

#define MAXN 1000010
#define F first
#define S second

int64_t s64() { int64_t res; scanf("%" PRId64, &res); return res; }
void p64(int64_t res) { printf("%" PRId64, res); }

int inp[MAXN];
char ans[MAXN];

int main()
{
    int casN;
    scanf("%d", &casN);
    for (int cas = 0; cas < casN; cas++)
    {
        int n, q;
        scanf("%d%d", &n,&q);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &inp[i]);
            ans[i] = '0';
        }
        ans[n] = 0;

        int cq = 0;
        for (int i = n-1; i >= 0; i--)
        {
            if (inp[i] <= cq)
            {
                ans[i] = '1';
            }
            else if (cq < q)
            {
                cq++;
                ans[i] = '1';
            }
        }
        printf("%s\n", ans);
    }

    return 0;
}