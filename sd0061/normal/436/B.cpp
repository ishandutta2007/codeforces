#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;
typedef long long LL;
#define N 2005
int n , m , K;
int cnt[N];
char s[N][N];

void work()
{
    int i , j , x , y;
    scanf("%d%d%d",&n,&m,&K);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%s" , s[i] + 1);
    for (i = 2 ; i <= n ; ++ i) {
        for (j = 1 ; j <= m ; ++ j) {
            if (s[i][j] == 'U') {
                if (i & 1)
                    ++ cnt[j];
            }
            if (s[i][j] == 'R') {
                if (i + j - 1 <= m)
                    ++ cnt[i + j - 1];
            }
            if (s[i][j] == 'L') {
                if (j - i + 1 > 0)
                    ++ cnt[j - i + 1];
            }
        }
    }
    for (i = 1 ; i <= m ; ++ i)
        printf("%d " , cnt[i]);
}

int main()
{
    //freopen("~input.txt" , "r" , stdin);
    work();
    return 0;
}