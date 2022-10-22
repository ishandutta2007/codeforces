#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <cstdio>
#include <algorithm>
#define N 100005
using namespace std;
int n , a[N] , ans = 1 << 30;
int main()
{
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  scanf("%d",&n);
  int i , x , top , bot , sum;
  for (i = 1 ; i <= n ;i ++)
    scanf("%d",&a[i]);
  sort(a + 1 , a + 1 + n);
  
  x = 1;
  for (i = 2 ; i <= n ;i ++)
  {
    while (a[x] * 2 < a[i])
      x ++;
    ans = min(ans , n - i + x - 1);  
  }
  cout << ans << endl;
  return 0;
}