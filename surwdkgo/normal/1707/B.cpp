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
        }

        for(int i = 1; i < n; i++)
        {
            inp[i-1] = inp[i] - inp[i-1];
        }
        n--;
        sort(inp, inp+n);

        int z = -1;
        while (z+1 < n && inp[z+1] == 0)
        {
            z++;
        }

        while (n > 1)
        {
            int st = max(z, 0);
            for (int i = st; i < n - 1; i++)
            {
                inp[i] = inp[i+1] - inp[i];
            }

            sort(inp+st, inp+n);

            z = st-1;
            while (z+1 < n && inp[z+1] == 0) z++;
            n--;
        }
        printf("%d\n", inp[0]);
    }

    return 0;
}