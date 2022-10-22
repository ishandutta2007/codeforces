#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <set>
#include <string>
#define N 100005
using namespace std;
typedef long long LL;
char s[N];
int n , num[N][3] , m;

void work()
{
    int i , j , l , r  , x[3];
    scanf("%s" , s + 1);
    n = strlen(s + 1);
    for (i = 1 ; i <= n  ;++ i)
    {
        for (j = 0 ; j < 3 ; ++ j)
            num[i][j] = num[i - 1][j];
        num[i][s[i] - 'x'] ++;
    }
    scanf("%d",&m);
    for (i = 1 ; i <= m ; ++ i)
    {
        scanf("%d%d",&l,&r);
        if (r - l + 1 <= 2) {puts("YES"); continue;}
        for (j = 0 ; j < 3 ; ++ j)
            x[j] = num[r][j] - num[l - 1][j];
        sort(x , x + 3);
        if (x[2] - x[0] <= 1)
            puts("YES");
        else puts("NO");
    }

}


int main()
{
    //freopen("~input.txt" , "r" , stdin);
        work();
    return 0;
}