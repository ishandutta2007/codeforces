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
        int n, inp, z;
        scanf("%d%d", &n, &z);
        int ans = 0;
        for (int i = 0; i < n ; i++)
        {
            scanf("%d", &inp);
            ans = max(ans, inp | z);
        }
        printf("%d\n", ans);

    }

    return 0;
}