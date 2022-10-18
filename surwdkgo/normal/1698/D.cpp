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
    scanf("%d",&casN);
    for (int iter=0; iter < casN; iter++)
    {
    int n;
    scanf("%d",&n);
    int l=0, r=n;

    while (r-l>1)
    {
        int m = (r+l)/2;
        printf("? %d %d\n", l+1, m);
        fflush(stdout);

        int cnt = 0;
        for (int i = l+1; i <= m; i++)
        {
            int ans;
            scanf("%d",&ans);
            cnt += ans >= l+1 && ans <=m ? 1 : 0;
        }

        if (cnt%2 == 0)
        {
            l = m;
        }
        else
        {
            r = m;
        }
    }
    printf("! %d\n", l+1);
    fflush(stdout);
    }

    return 0;
}