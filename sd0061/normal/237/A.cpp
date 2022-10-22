#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 100005
int f[25][60];
int n,x,y,ans;
int main()
{
  cin >> n;
  for (int i = 1 ; i <= n ;i ++)
  {
    scanf("%d %d",&x,&y);  
    f[x][y] ++;
  }  
  for (int i = 0 ;i < 24 ;i ++)
    for (int j = 0 ;j < 60 ;j ++)
      ans = max(ans,f[i][j]);
  cout << ans;    
  return 0;    
}