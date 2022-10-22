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
#include <utility>
#include <map>
typedef long long LL;
using namespace std;
#define N 305

int n;
char s[N][N];

void work()
{
    int i , j;
    scanf("%d",&n);
    for (i = 0 ; i < n ; ++ i)
        scanf("%s" , s[i]);
    char x = s[0][0] , y = s[0][1];
    for (i = 0 ; i < n ; ++ i) {
        for (j = 0 ; j < n ; ++ j) {
            if (i == j || i + j + 1 == n) {
                if (s[i][j] != x)
                    break;
            }else {
                if (s[i][j] != y)
                    break;
            }
        }
        if (j < n)
            break;
    }
    if (i >= n && x != y)
        puts("YES");
    else
        puts("NO");
}

int main()
{
//    freopen("~input.txt" , "r" , stdin);
        work();
    return 0;
}