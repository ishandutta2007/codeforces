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

int n;
char cur[MAXN];
char goa[MAXN];

int main()
{
    int casN;
    scanf("%d", &casN);
    for (int cas = 0; cas < casN; cas++)
    {
        scanf("%d", &n);
        scanf("%s%s", cur, goa);

        int64_t ans = 0;

        if (cur[0] != goa[0] || cur[n-1] != goa[n-1])
        {
            printf("-1\n");
            continue;
        }

        char extV[2] = {};
        int extP = 0;
        for (int i = 1; i < n-1; i++)
        {
            char curV = extP >= i ? extV[i%2] : cur[i];
            char nxtV = extP >= i+1 ? extV[(i+1)%2] : cur[i+1];
            char preV = goa[i-1];
            // printf("iter %d ext [%c %c] %d\n", i, extV[0], extV[1], extP);
            //printf("%c %c %c\n", preV, curV, nxtV);
            if (curV == goa[i]) continue;

            if (preV != nxtV)
            {
                //printf("flip next\n");
                ans++;
                continue;
            }

            extP = max(extP, i+1);
            extV[i%2] = curV;
            extV[(i+1)%2] = nxtV;

            while (extP+1 < n && cur[extP+1] == extV[(extP+1)%2]) extP++;

            if (extP == n-1)
            {
                ans = -1;
                break;
            }

            ans += extP - i + 1;
            //printf("flip %d\n", extP - i + 1);
            extV[0] = extV[0] == '0' ? '1' : '0';
            extV[1] = extV[1] == '0' ? '1' : '0';
        }

        printf("%" PRId64 "\n", ans);

    }

    return 0;
}