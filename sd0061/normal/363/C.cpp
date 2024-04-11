#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
#define N 200005

int n , K;
char s[N] , t[N];

void work()
{
    int i , j , x = 0;
    scanf("%s" , s);
    for (i = 0 ; s[i] ; ++ i)
        if (i < 2 || !(s[i] == s[i - 1] && s[i - 1] == s[i - 2]))
            t[n ++] = s[i];
    for (i = 0 ; i < n ; ++ i)
    {
        j = 1;
        while (t[i] == t[i + j])
            ++ j;
        if (j == 1)
            putchar(t[i]) , x = 0;
        else
        {
            putchar(t[i]) , x ^= 1;
            if (x)
                putchar(t[i]);
            ++ i;
        }

    }
}

int main()
{
    //freopen("~input.txt" , "r" , stdin);
    //int _; scanf("%d",&_); while (_ --)
    //while (~scanf("%d%d%d",&n,&m,&k))
        work();
    return 0;
}