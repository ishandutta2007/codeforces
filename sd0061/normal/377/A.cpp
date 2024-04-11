#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <list>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
#define N 505
int n , m , S;
char s[N][N];
bool f[N][N];
vector< pair<int , int> > ans;

void dfs(int x , int y)
{
    if (f[x][y]) return;
    f[x][y] = 1;
    if (s[x][y - 1] == '.')
        dfs(x , y - 1);
    if (s[x][y + 1] == '.')
        dfs(x , y + 1);
    if (s[x - 1][y] == '.')
        dfs(x - 1 , y);
    if (s[x + 1][y] == '.')
        dfs(x + 1, y);
    if (S)
        -- S , ans.push_back(mp(x , y));
}

void dfs1(int x , int y)
{
    if (f[x][y]) return;
    f[x][y] = 1;
    if (s[x][y - 1] == '.')
        dfs1(x , y - 1);
    if (s[x][y + 1] == '.')
        dfs1(x , y + 1);
    if (s[x - 1][y] == '.')
        dfs1(x - 1 , y);
    if (s[x + 1][y] == '.')
        dfs1(x + 1, y);
    ans.push_back(mp(x , y));
}

void work()
{
    int i , j , x , y;
    scanf("%d%d%d",&n,&m,&S);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%s" , s[i] + 1);
    for (i = 1 ; i <= n ; ++ i)
        for (j = 1 ; j <= m ; ++ j)
            if (s[i][j] == '.')
                x = i , y = j;
    dfs(x , y);
    for (i = 0 ; i < ans.size() ; ++ i)
        s[ans[i].first][ans[i].second] = 'X';
    for (i = 1 ; i <= n ; ++ i)
        puts(s[i] + 1);
}

int main()
{
    //freopen("~input.txt" , "r" , stdin);
    //int _; scanf("%d",&_); while (_ --)
    //while (~scanf("%d",&n))
        work();
    return 0;
}