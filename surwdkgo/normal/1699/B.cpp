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
        for (int i = 0; i<n;i++)
        {
            int di=((i+1)%4)/2;
            for (int j = 0; j<m; j++)
            {
                int dj=((j+1)%4)/2;
                printf("%d%c", di^dj, j == m-1 ? '\n' : ' ');
            }
        }

    }

    return 0;
}