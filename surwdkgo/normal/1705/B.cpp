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

int inp[MAXN];
int main()
{
    int casN;
    scanf("%d", &casN);
    for (int cas = 0; cas < casN; cas++)
    {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) scanf("%d", &inp[i]);

        int64_t ans = 0;
        int64_t sum = 0;
        for (int i = 0; i < n-1; i++)
        {
            if (sum > 0 && inp[i] == 0)
            {
                ans++;
            }
            sum += inp[i];
            ans += inp[i];
        }
        printf("%" PRId64"\n", ans);

    }

    return 0;
}