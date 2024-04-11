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
        int n;
        int nz = 0;
        bool lz = false;
        int inp;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", & inp);
            if (inp > 0)
            {
                if (lz) continue;
                else{
                    lz = true;
                    nz++;
                }
            }
            else
            {
                lz = 0;
            }
        }

        if (nz == 0)
            printf("0\n");
        else if (nz == 1)
            printf("1\n");
        else printf("2\n");
    }

    return 0;
}