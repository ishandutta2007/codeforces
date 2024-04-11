#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <set>
#include <climits>
using namespace std;
#define N 1000005
#define M 500005

int n , a[N] , m;
char s[N];

void work()
{
    int i , j , x = 0 , ans = 0;
    m = strlen(s) , n = 0;
    i = 0;
    while (i < m && s[i] == 'F') ++ i;

    for ( ; i < m ; ++ i)
        if (s[i] == 'F')
            a[n ++] = x;
        else ++ x;
    if (n == m || n == 0)
    {
        puts("0");
        return;
    }
    x = ans = a[0];
    for (i = 1 ; i < n ; ++ i)
    {
        if (a[i] == x)
            ++ x;
        else if (a[i] <= x)
            ++ x;
        else x = a[i];
        ans = max(ans , x);
    }
    cout << ans << endl;
}

int main()
{
  //freopen("~output.txt","w",stdout);
  while (~scanf("%s", s))
  //int _; cin >> _;while (_--)
    work();
  return 0;
}