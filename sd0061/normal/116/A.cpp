#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int n, sum ,ans = - 1 << 30;
int main()
{
  int i ,x , y;
  scanf("%d",&n);
  for (i = 1 ;i <= n ;i ++)
  {
    scanf("%d %d",&x,&y);
    sum += y - x;
    ans = max(sum,ans);  
  }  
  printf("%d",ans);
  return 0;
}