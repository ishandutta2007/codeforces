#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
#define N 100005
int n , a[N] , ans , s[N] , k;

int main()
{
  int i , x , l , r ;
  cin >> n >> k;
  a[0] = k + 1;  
  for (i = 1 ;i <= n ;i ++)
  {
    scanf("%d",&a[i]);
    if (a[i] == a[i - 1])
      i -- , n --;
  }
  a[n + 1] = 0;
  for (i = 1 ;i <= n ;i ++)
  {
    s[a[i]] += 2;
    if (a[i - 1] != a[i + 1])
      s[a[i]] --;
  }  
  for (i = 1; i <= k ; i ++)
    if (!ans || s[i] > s[ans])
      ans = i;
  cout << ans;    
  return 0;    
}