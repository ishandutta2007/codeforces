#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;
#define N 55
int n , a[N] , k ,sum;
vector<int> s[N*N];
int main()
{
  int i , j ;
  cin >> n >> k;
  for (i = 0 ;i < n ;i ++)
    cin >> a[i];
  sort(a ,a + n);
  
  for (i = 0 ;i < n ;i ++)
    for (j = 0 ;j + i < n ;j ++)
    {
      for (int l = n - 1 ; l >= n - i ; l --)
        s[sum].push_back(a[l]);
      s[sum ++].push_back(a[j]);    
    }
  for (i = 0 ;i < k ;i ++)
  {
    printf("%d ",s[i].size());
    for (j = 0 ;j < s[i].size() ;j ++)
      printf("%d ",s[i][j]);
    printf("\n");    
  }
  return 0;    
}