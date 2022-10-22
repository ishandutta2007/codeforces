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
#define N 105


int n , k;
char s[N];

void work()
{
    int i , j;
    scanf("%d%d",&n,&k);
    scanf("%s" , s + 1);
    if (k <= n / 2) {
        for (i = k ; i > 1 ; -- i)
            puts("LEFT");
        for (i = 1 ; i <= n ; ++ i) {
            printf("PRINT %c\n" , s[i]);
            if (i < n)
                puts("RIGHT");
        }
    } else {
        for (i = k ; i < n ; ++ i)
            puts("RIGHT");
        for (i = n ; i >= 1 ; -- i) {
            printf("PRINT %c\n" , s[i]);
            if (i > 1)
                puts("LEFT");
        }
    }
}

int main()
{
    //freopen("~input.txt" , "r" , stdin);
//while (scanf("%d",&n) , n)
        work();
    return 0;
}