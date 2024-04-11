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

int inp[MAXN];

int main()
{
    int casN;
    scanf("%d", &casN);
    for (int cas = 0; cas < casN; cas++)
    {
        int n,k;
        scanf("%d%d", &n,&k);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &inp[i]);
        }

        if (k == 1)
        {
            printf("%d\n", (n-1)/2);
        }
        else
        {
            int ans = 0;
            for (int i = 1; i<n-1; i++)
            {
                ans += inp[i] > inp[i-1]+inp[i+1] ? 1 : 0;
            }
            printf("%d\n", ans);
        }

    }

    return 0;
}