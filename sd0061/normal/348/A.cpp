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
//#pragma comment(linker, "/STACK:16777216")
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define N 100005

int n , a[N];
void work()
{
    int i , x = 0; LL sum = 0;
    scanf("%d",&n);
    for (i = 0 ; i < n ; ++ i)
        scanf("%d",&a[i]) , x = max(x , a[i]);
    LL l = x , r = 2e9;
    while (l < r)
    {
        LL m = (l + r) >> 1;
        sum = 0;
        for (i = 0 ; i < n ; ++ i)
            sum += (m - a[i]);
        if (sum >= m)
            r = m;
        else l = m + 1;
    }
    cout << l << endl;
}

int main()
{
    //freopen("~input.txt" , "r" , stdin);
    //int _; scanf("%d" , &_); while (_--)
    //while (~scanf("%d",&n))
    //for (n = 1 ; n <= 9 ; ++ n)
        work();
    return 0;
}