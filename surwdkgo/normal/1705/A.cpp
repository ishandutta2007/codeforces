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
        int n,x;
        scanf("%d%d", &n, &x);
        for (int i = 0; i < 2*n; i++)
        {
            scanf("%d", &inp[i]);
        }
        sort(inp, inp+2*n);

        bool ans = true;
        for (int i = 0; i < n; i++)
        {
            if (inp[i+n] < inp[i] + x)
            {
                ans = false;
                break;
            }
        }
        printf("%s\n", ans ? "YES" : "NO");

    }

    return 0;
}