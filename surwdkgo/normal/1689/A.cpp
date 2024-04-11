#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    char s1[210], s2[210];
    int cas;
    scanf("%d", & cas);

    for (int iter = 0; iter < cas; iter++)
    {
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);
        scanf("%s%s", s1, s2);

        std::sort(s1, s1+n);
        std::sort(s2, s2+m);

        char* s[2] = {s1, s2};
        int c[2] = {0,0}, u = 0, l = 0;
        while (c[0] < n && c[1] < m)
        {
            if (l == k || s[1-u][c[1-u]] < s[u][c[u]])
            {
                printf("%c", s[1-u][c[1-u]]);
                c[1-u]++;
                u = 1-u;
                l = 1;
            }
            else
            {
                printf("%c", s[u][c[u]]);
                c[u]++;
                l++;
            }
        }
        printf("\n");
    }

    return 0;
}