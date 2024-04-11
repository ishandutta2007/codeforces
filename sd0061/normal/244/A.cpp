#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 100005

int n , k, a[N];
vector<int> ans[N];
bool f[N];
int main()
{
  int i , j , x;
  cin >> n >> k;
  for (i = 1 ;i <= k ;i ++)
  {
    cin >> x;
    f[x] = 1 , ans[i].push_back(x);  
  }
  for (j = 1 ;j <= k ;j ++)
    for (i = 1 ;i <= n * k && ans[j].size() < n;i ++)
      if (!f[i])
        f[i] = 1 ,ans[j].push_back(i);
  for (i = 1 ;i <= k ;i ++)
  {
    //sort(ans[i].begin,ans[i].end);
    for (j = 0 ;j < n ;j ++)
      printf("%d ",ans[i][j]);
    printf("\n")    ;
  }       
  return 0;    
}