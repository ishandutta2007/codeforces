#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
#define N 100005
int n , a[N] , ans;

int main()
{
  int i , x , j ;
  cin >> n;
  j = 0;
  for ( i = 1 ;i <= n ;i ++)
  {
    cin >> x;
    if (x < 0)
    {
      j ++;
      if (j > 2)
        j = 1 , a[ans ++] = i - 1;  
    }  
  } 
  a[ans ++] = n; 
  cout << ans << endl;
  for (i = 0 ; i < ans ; i ++)
    printf("%d ",a[i] - a[i - 1]);
  return 0;    
}