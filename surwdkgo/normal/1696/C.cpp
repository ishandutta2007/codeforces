#include <cstdio>
#include <cstdint>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <deque>

using namespace std;

#define MAXN 100010
#define F first
#define S second

int a[2][MAXN];
int64_t am[2][MAXN];

int main()
{
    int casN;
    scanf("%d", &casN);
    for (int cas = 0; cas < casN; cas++)
    {
        int n[2],m;
        scanf("%d%d", &n[0], &m);
        for (int i = 0; i < n[0] ; i++)
        {
            scanf("%d", & a[0][i]);
        }
        scanf("%d", &n[1]);
        for (int i = 0; i < n[1]; i++)
        {
            scanf("%d", &a[1][i]);
        }

        for (int i = 0; i < 2 ; i++)
        {
            for (int j = 0; j < n[i]; j++)
            {
                am[i][j] = 1;
                while (a[i][j] % m == 0)
                {
                    a[i][j] /= m;
                    am[i][j] *= m;
                }
            }
        }

        int x[2];
        for (int i = 0; i < 2; i++)
        {
            x[i] = 1;
            for (int j = 1; j < n[i]; j++)
            {
                if (a[i][x[i]-1] == a[i][j])
                {
                    am[i][x[i]-1] += am[i][j];
                }
                else
                {
                    x[i]++;
                    a[i][x[i]-1] = a[i][j];
                    am[i][x[i]-1] = am[i][j];
                }
            }
        }

        bool ans = true;
        if (x[0] != x[1]) ans = false;
        else
        {
            for (int i = 0; i < x[0]; i++)
            {
                if (a[0][i] != a[1][i]) ans = false;
                if (am[0][i] != am[1][i]) ans = false;
            }
        }
#if 0
        for (int j = 0; j < 2; j++)
        for (int i = 0; i < x[j]; i++) printf("(%d,%d)%c", a[j][i], am[j][i], i == x[j]-1 ? '\n' : ' ');
#endif
        printf ("%s\n", ans ? "Yes" : "No");

    }

    return 0;
}