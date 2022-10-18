#include <cstdio>
#include <cstdint>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <deque>

using namespace std;

#define MAXN 1010
#define F first
#define S second

int inp[MAXN][MAXN];
int mi[MAXN][MAXN];
int ma[MAXN][MAXN];

int main()
{
    int casN;
    scanf("%d", &casN);
    for (int cas = 0; cas < casN; cas++)
    {
        int n, m;
        scanf("%d%d", &n, &m);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j< m; j++)
            {
                scanf("%d", &inp[i][j]);

                int nmi = 1e9;
                int nma = -1e9;

                if (i > 0)
                {
                    nmi = min(nmi, mi[i-1][j] + inp[i][j]);
                    nma = max(nma, ma[i-1][j] + inp[i][j]);
                }
                if (j > 0)
                {
                    nmi = min(nmi, mi[i][j-1] + inp[i][j]);
                    nma = max(nma, ma[i][j-1] + inp[i][j]);
                }
                if (i != 0 || j != 0)
                {
                    mi[i][j] = nmi;
                    ma[i][j] = nma;
                }
                else
                {
                    mi[0][0] = inp[0][0];
                    ma[0][0] = inp[0][0];
                }
            }
        }
/*
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                printf("%d ", mi[i][j]);
            }
            printf("\n");
        }

        printf("---\n");
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                printf("%d ", ma[i][j]);
            }
            printf("\n");
        }*/

        printf ("%s\n", mi[n-1][m-1] <= 0 && ma[n-1][m-1]>=0 && (n+m)%2 == 1  ? "YES" : "NO");

    }

    return 0;
}