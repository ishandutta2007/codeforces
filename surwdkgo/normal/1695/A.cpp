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

int main()
{
    int casN;
    scanf("%d", &casN);
    for (int cas = 0; cas < casN; cas++)
    {
        int n,m;
        scanf("%d%d", &n,&m);
        int inp;
        int ma = -2e9;
        int x,y;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j<m; j++)
            {
                scanf("%d", &inp);
                if (inp > ma)
                {
                    ma = inp;
                    x = i;
                    y = j;
                }
            }
        }
        int i = x;
        int j = y;
        int64_t ans = (i+1ll)*(j+1ll);
        ans = max<int64_t>(ans, ((int64_t)n-i) * ((int64_t)m-j));
        ans = max<int64_t>(ans, ((int64_t)n-i) * (j+1ll));
        ans = max<int64_t>(ans, (i+1ll) * ((int64_t)m-j));
        printf("%lu\n", ans);

    }

    return 0;
}