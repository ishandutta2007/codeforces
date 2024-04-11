#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
#define N 100005
int n;
double p[N],ans;
int main()
{
  int i ,j; double x = 0, y = 0;  
  cin >> n;
  for (i = 1 ;i <= n ;i ++)
    cin >> p[i];
  for (i = 1 ;i <= n ;i ++)
  {
    y *= p[i - 1]; 
    x += y * 2 ;
    y += 1 - p[i - 1];
    x += 1 - p[i - 1];
    x *= p[i];
    ans += x;  
  }  
  printf("%.15lf",ans);
  return 0;    
}