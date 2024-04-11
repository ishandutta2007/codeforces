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
#include <set>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define N 100005
int n , a[N];
int ans , p;
void work()
{
  int i , j , x , y , k;
  cin >> n;
  p = 0;
  for (i = 1 ; i <= n ; ++ i)
    scanf("%d",&a[i]);
  for (j = 30 ;j >= 0 ; -- j)
  {
    x = 0 , y = (1 << 30) - 1;
    for (i = 1 ; i <= n ; ++ i)
      if (a[i] & (1 << j))
      {
        ++ x ;
        y &= a[i];
      }

    if (x && (y & -y) > p)
    {
      p = (y & -y);
      k = j;
      ans = x;
    }
    else if ((y & -y) == p && x > ans)
    {
            k = j;
      ans = x;
    }
  }
    printf("%d\n" , ans);
    for (i = 1 ; i <= n ; ++ i)
      if (a[i] & (1 << k))
        printf("%d " , a[i]);

}

int main()
{
  //init();
 // int _; scanf("%d",&_); while (_--)
    work();
  return 0;
}