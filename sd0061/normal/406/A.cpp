#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long LL;

#define N 1005
int n , a[N][N] , m;
int r[N] , c[N];
void work()
{
    int i , j;
    scanf("%d",&n);
    for (i = 1 ; i <= n ; ++ i) {
        for (j = 1 ; j <= n ; ++ j)
            scanf("%d",&a[i][j]) , r[i] += a[i][j] , c[j] += a[i][j];
    }
    int ans = 0;
    for (i = 1 ; i <= n ; ++ i) {
        for (j = 1 ; j <= n ; ++ j)
            ans ^= a[i][j] & a[j][i];
    }
    scanf("%d",&m);
    while (m --) {
        scanf("%d",&i);
        if (i == 3) {
            printf("%d" , ans);
        }
        else {
            scanf("%d",&i);
                ans ^= 1;

        }
    }

}

int main()
{
    //freopen("~input.txt" , "r" , stdin);
    work();
    return 0;
}