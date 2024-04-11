#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <cstdio>
#include <algorithm>
#define N 4005
using namespace std;
int n, a[N] , f[N][N] , ans = 1;
vector<int> h[1000005];


int main()
{
  int i , j ,  x , y;
  scanf("%d",&n);
  for (i = 1 ; i <= n ;i ++)
    scanf("%d",&a[i]) , h[a[i]].push_back(i);
  for (i = 1 ; i <= n ;i ++)
  {
    x = a[i] , f[i][i] = 1 , y = h[x].size() - 1;
    for (j = i - 1 ;j > 0 ;j --)
    {
      f[j][i] = 2;
      for(int& k = y ; k >= 0 ; k --)
        if (h[x][k] < j)
        {
          f[j][i] = f[h[x][k]][j] + 1;
          break;
        }
      ans = max(f[j][i] , ans);
    }
  }
  cout << ans << endl;
  return 0;
}