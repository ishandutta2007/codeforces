#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;
typedef long long LL;
#define N 100005
int n , a[N] , cnt;
pair<int , int> b[N];

int main()
{
    //freopen("~input.txt" , "r" , stdin);
    scanf("%d",&n);
    int i , j , x = 1;
    for (i = 1 ; i <= n ; ++ i)
        scanf("%d",&a[i]);
    for (i = 1 ; i <= n + 1; ++ i)
        if (a[i])
            b[cnt ++] = make_pair(-a[i] , i);
        else
        {
            sort(b , b + cnt);
            if (cnt == 0)
            {
                if (i != n + 1)
                    puts("0");
            }
            else if (cnt == 1)
            {
                puts("pushStack");
                if (i != n + 1)
                    printf("1 popStack\n");
            }
            else if (cnt == 2)
            {
                puts("pushStack\npushQueue");
                if (i != n + 1)
                    printf("2 popStack popQueue\n");
            }
            else
            {
                for (j = x ; j < i ; ++ j)
                    if (j == b[0].second)
                        puts("pushStack");
                    else if (j == b[1].second)
                        puts("pushQueue");
                    else if (j == b[2].second)
                        puts("pushFront");
                    else puts("pushBack");
                if (i != n + 1)
                    printf("3 popStack popQueue popFront\n");
            }
            cnt = 0 , x = i + 1;
        }

    return 0;
}