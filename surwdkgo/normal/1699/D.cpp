#include <cstdio>
#include <cstdint>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <deque>

using namespace std;

#define MAXN 5010
#define F first
#define S second

int inp[MAXN];
int n;
int tron[MAXN];
int cnt[MAXN];

int main()
{
    int casN;
    scanf("%d", &casN);
    for (int cas = 0; cas < casN; cas++)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &inp[i]);
            cnt[i+1] = 0;
        }

        int* dp = tron+1;
        dp[-1] = 0;
        for (int i = 0; i <= n; i++)
        {
            dp[i] = -1;
            int mxc = 0;
            for (int j = i-1; j >= -1; j--)
            {
                // need to eliminate (j, i)
                //
                int tot = i - j - 1;
                if (tot % 2 == 0 && mxc <= tot/2 && dp[j] >= 0 && (j == -1 || i == n || inp[i] == inp[j]))
                {
                    //printf("%d -> %d\n", j, i);
                    dp[i] = max(dp[i], dp[j]+1);
                }
                if (j == -1) break;
                cnt[inp[j]]++;
                mxc = max(mxc, cnt[inp[j]]);
            }

            for (int j = i-1; j>=0; j--)
            {
                cnt[inp[j]] = 0;
            }
        }
        printf("%d\n", dp[n]-1);
    }

    return 0;
}