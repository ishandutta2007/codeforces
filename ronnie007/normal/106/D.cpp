#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define maxn 1005
#define maxm 100005

struct S
{
    char c;
    int x, y;
};

S s[maxm];

int n, m, k, p;
bool gra[maxn][maxn];
char dir[maxm];
int len[maxm], cmap[256], nn[maxn][maxn], ns[maxn][maxn], ne[maxn][maxn], nw[maxn][maxn];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

bool cmp(S s1, S s2)
{
    return s1.c < s2.c;
}
void read()
{
    p = 0;
    int i, j;
    char c;
    for(i = 1; i <= n; ++i)
    {
        for(j = 1; j <= m; ++j)
        {
           scanf("%c", &c);
           if(c == '#')
           {
               gra[i][j] = false;
           }
           else
           {
               gra[i][j] = true;
               if(c >= 'A' && c <= 'Z')
               {
                   ++p;
                   s[p].y = i;
                   s[p].x = j;
                   s[p].c = c;
               }
           }
        }
        scanf("%*c");
    }
    scanf("%d%*c", &k);
    for(i = 1; i <= k; ++i)
    {
        scanf("%c%*c%d%*c", &dir[i], &len[i]);
    }
    sort(&s[1], &s[1] + p, cmp);
}
void init()
{
    memset(ns, 0, sizeof(ns));
    memset(nn, 0, sizeof(nn));
    memset(ne, 0, sizeof(ne));
    memset(nw, 0, sizeof(nw));
    int i, j;
    for(i = 1; i <= n; ++i)
    {
        for(j = 1; j <= m; ++j)
        {
            nw[i][j] = gra[i][j] ? nw[i][j - 1] : nw[i][j - 1] + 1;
        }
        for(j = m; j >= 1; --j)
        {
            ne[i][j] = gra[i][j] ? ne[i][j + 1] : ne[i][j + 1] + 1;
        }
    }
    for(j = 1; j <= m; ++j)
    {
        for(i = 1; i <= n; ++i)
        {
            nn[i][j] = gra[i][j] ? nn[i - 1][j] : nn[i - 1][j] + 1;
        }
        for(i = n; i >= 1; --i)
        {
            ns[i][j] = gra[i][j] ? ns[i + 1][j] : ns[i + 1][j] + 1;
        }
    }

//    printf("nn\n");
//    for(i = 1; i <= n; ++i)
//    {
//        for(j = 1; j <= m; ++j)
//        {
//            printf("%d ", nn[i][j]);
//        }
//        printf("\n");
//    }
}
void solve()
{
    bool tag = false;
    int x, y, xx, yy, i, j ,flag;
    for(i = 1; i <= p; ++i)
    {
        x = s[i].x;
        y = s[i].y;
        for(j = 1; j <= k; ++j)
        {
            flag = cmap[int(dir[j])];

            xx = x + (dx[flag] * len[j]);
            yy = y + (dy[flag] * len[j]);

            if(!(xx >= 1 && xx <= m && yy >= 1 && yy <= n))
            {
                break;
            }
            else if(flag == 0 && nn[y][x] - nn[yy - 1][xx] > 0) //N
            {
                break;
            }
            else if(flag == 1 && ns[y][x] - ns[yy + 1][xx] > 0) //S
            {
                break;
            }
            else if(flag == 2 && nw[y][x] - nw[yy][xx - 1] > 0) //W
            {
                break;
            }
            else if(flag == 3 && ne[y][x] - ne[yy][xx + 1] > 0) // e
            {
                break;
            }
            x = xx;
            y = yy;
        }//end for
        if(j > k)
        {
            printf("%c", s[i].c);
            tag = true;
        }
    }
    if(!tag)
    {
        printf("no solution");
    }
    printf("\n");
}
int main()
{

    cmap['N'] = 0;
    cmap['S'] = 1;
    cmap['W'] = 2;
    cmap['E'] = 3;
    while(scanf("%d%*c%d%*c", &n, &m) != EOF)
    {
        read();
        init();
        solve();
    }
    return 0;
}