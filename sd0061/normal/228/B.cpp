#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
#define N 55
int na,nb,ma,mb,a[N][N],b[N][N],ans,ansx,ansy,sum;
int main()
{
  int i ,j , x ,y;char c;
  scanf("%d %d\n",&ma,&na);
  for (i = 1 ;i <= ma ;i ++)
  {
    for (j = 1 ; j <= na ;j ++)
      a[i][j] = getchar() - '0';
    getchar();    
  }  
  scanf("%d %d\n",&mb,&nb);
  for (i = 1 ;i <= mb ;i ++)
  {
    for (j = 1 ; j <= nb ;j ++)
      b[i][j] = getchar() - '0';
    getchar();    
  }  
  for (x = -50 ; x <= 50 ; x ++)
    for (y = -50 ; y <= 50 ; y ++)
    {
      sum = 0;
      for (i = 1 ; i <= ma ; i ++)
        if (i + x >= 1 && i + x <= mb)
          for (j = 1 ;j <= na ; j ++)
            if (j + y >= 1 && j + y <= nb)
              sum += a[i][j] * b[i + x][j + y];
      if (sum >= ans)
        ans = sum , ansx = x , ansy = y;        
    }
  cout << ansx << " " << ansy << endl;
  return 0;  
}