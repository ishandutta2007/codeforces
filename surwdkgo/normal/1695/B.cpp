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
        scanf("%d", &n);
        int mi[2] = {1<<30, 1<<30};
        int ro[2];
        for (int i = 0; i< n; i++)
        {
            int inp;
            scanf("%d", &inp);

            if (inp < mi[i%2])
            {
                mi[i%2] = inp;
                ro[i%2] = i;
            }
        }
        if (n%2 == 0)
        {
            printf("%s\n", (mi[0] > mi[1] || mi[0] == mi[1] && ro[0] > ro[1]) ? "Mike" : "Joe");
        }
        else
        {
            printf("Mike\n");
        }
    }

    return 0;
}