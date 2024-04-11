#include <cstdio>
#include <cstdint>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <deque>

using namespace std;

#define MAXN 5000010
#define F first
#define S second

int dp[MAXN];
bool usd[MAXN];
int inp[MAXN];

int main()
{
    int casN;
    scanf("%d", &casN);
    for (int cas = 0; cas < casN; cas++)
    {
        int n, m;
        scanf("%d%d", &n, &m);

        int mi = MAXN, ma = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", & inp[i]);
            usd[inp[i]] = 1;
            mi = min(mi, inp[i]);
            ma = max(ma, inp[i]);
        }

        int ans = ma - mi;

        int st = sqrt(ma)+1;

        map<int,int> mp;
        for (int i = 1; i <= ma ; i++)
        {
            dp[i] = i >= st ? i : 2*MAXN;
            if (usd[i])
            {
                mp[dp[i]]++;
            }
        }

        auto upd = [&mp](int prev, int nv)
        {
            //printf("%d -> %d %d\n", prev, nv, mp[prev]);
            mp[prev]--;
            if (mp[prev] == 0)
            {
                mp.erase(prev);
            }
            mp[nv]++;
        };

        for (int minv = st; minv >=1; minv--)
        {
            //printf("minv: %d\n", minv);

            // dp[i]: minimum max v when min is minv
            if (usd[minv]) upd(dp[minv], minv);
            dp[minv] = minv;
            for (int i = minv; i * minv <= ma; i++)
            {
                if (dp[i * minv] > dp[i])
                {
                    if (usd[i*minv]) upd(dp[i * minv], dp[i]);
                    dp[i * minv] = dp[i];
                }
            }
            if (minv <= mi)
            {
              //  printf("res: %d\n", (--mp.end())->first);
                ans = min(ans, (--mp.end())->first - minv);
            }
        }

        for (int i = 0; i < n; i++) usd[inp[i]] = 0;
        printf("%d\n", ans);

    }

    return 0;
}