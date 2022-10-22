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
typedef unsigned long long ULL;
#define N 100005

int n , a[N];

void work()
{
    int i;
    scanf("%d",&n);
    if (n & 1)
    {
        a[1] = n;
        for (i = 2 ; i <= n ; ++ i)
            a[i] = i - 1;
    }
    else
    {
        for (i = 1 ; i <= n ; ++ i)
            if (i & 1)
                a[i] = i + 1;
            else a[i] = i - 1;
    }
    for (i = 1 ; i <= n ; ++ i)
        printf("%d%c" , a[i] , " \n"[i == n]);
}

int main()
{
//    freopen("~input.txt" , "r" , stdin);
//    freopen("output.txt" , "w" , stdout);
//    int _; scanf("%d", &_) ; while (_ --)
//    while (~scanf("%s", s))
        work();
    return 0;
}