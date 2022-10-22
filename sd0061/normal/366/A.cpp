#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <set>
#include <string>
#define N 200005
using namespace std;
int n , a , b , c , d;
void  work()
{
    cin >> n;
    for (int i = 1 ; i <= 4 ; ++ i)
    {
        cin >> a >> b >> c >> d;
        if (a + d <= n)
        {
            printf("%d %d %d\n" , i , a , n - a);
            return;
        }
        if (a + c <= n)
        {
            printf("%d %d %d\n" , i , a , n - a);
            return;
        }
        if (b + d <= n)
        {
            printf("%d %d %d\n" , i , b , n - b);
            return;
        }
        if (b + c <= n)
        {
            printf("%d %d %d\n" , i , b , n - b);
            return;
        }
    }
    puts("-1");
}


int main()
{
    //freopen("~input.txt" , "r" , stdin);
        work();
    return 0;
}