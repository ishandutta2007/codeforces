#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 100005
int n , ans;
int m[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int f[1370];
int main()
{
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout); 
  int i , j, x , y , z , k;
  scanf("%d",&n);
  for (i = 1 ; i <= 12 ; i ++)
    m[i] += m[i - 1];
  for (i = 1 ;i <= n; i ++)
  {
    scanf("%d %d %d %d\n",&x,&y,&k,&z);
    x = m[x - 1] + y;
    for (j = 1000 + x - 1 ; j >= 1000 + x - z ; j --)
      f[j] += k , ans = max(f[j] , ans);
  }
  cout << ans << endl;
  return 0;    
}