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

int64_t op[55][4];
int64_t len;
int64_t mx = (1ull << 62) - 1;
char inp[MAXN];

int main()
{
    int casN;
    scanf("%d", &casN);
    for (int cas = 0; cas < casN; cas++)
    {
        int n, q;
        scanf("%" PRId64 "%d%d", &len, &n, &q);

        scanf("%s", inp);
        int realN = -1;
        for (int i = 0; i < n; i++)
        {
            scanf("%" PRId64 "%" PRId64, &op[i][0], &op[i][1]);
            int64_t delta = op[i][1] - op[i][0] + 1;
            op[i][2] = len+1;
            op[i][3] = op[i][2] + delta - 1;
            len += delta;

            if (len > mx && realN == -1)
            {
                realN = i;
            }
        }
        if (realN == -1) realN = n-1;

        for (int i = 0; i < q; i++)
        {
            int64_t pos;
            scanf("%" PRId64, &pos);

            for (int j = realN; j>=0; j--)
            {
                if (pos >= op[j][2] && pos <= op[j][3])
                {
                    pos -= op[j][2] - op[j][0];
                }
            }

            printf("%c\n", inp[pos-1]);
        }
    }

    return 0;
}