#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstring>
#define N 4
using namespace std;
int a[N][N];
int main()
{
  int i , j;
  for (i = 1 ; i <= 3 ;i ++)
    for (j = 1 ; j <= 3 ;j ++)
      cin >> a[i][j];
  a[2][2] = (a[1][2] + a[3][2]) >> 1;
  a[1][1] = a[2][2] + a[3][1] - a[1][2];
  a[3][3] = a[2][2] + a[1][3] - a[3][2];
  for (i = 1 ; i <= 3 ;i ++)
  {
    for (j = 1 ; j <= 3 ;j ++)
      printf("%d ",a[i][j]);
    printf("\n");  
  }    
  return 0;    
}