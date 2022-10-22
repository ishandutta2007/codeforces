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
#define N 105

int n , m , a[N][N];

void work()
{
    int i , j , ans = 4;
    scanf("%d%d",&n,&m);
    for (i = 1 ; i <= m ; ++ i)
        printf("%d %d " , 2 * i , 2 * i - 1);
    for (i = m + 1 ; i <= n ; ++ i)
        printf("%d %d " , 2 * i - 1 , 2 * i);
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