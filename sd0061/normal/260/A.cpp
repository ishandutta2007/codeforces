#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <queue>
#include <stack>
#include <utility>
#include <map>
#define pb push_back
#define mp make_pair
#define N 10002
using namespace std;
typedef long long LL;
//const LL Q = 1000000007LL;
int n , a , b;
vector<int> ans;
void work()
{
  int i , j , x = a % b;
  for (i = 1 ; i <= n ;i ++)
  {
    for (j = 0 ; j < 10 ;++ j)
      if ((x * 10 + j) % b == 0)
      {
        ans.pb(j);
        x = x * 10 + j;
        x %= b;
        break;
      }
    if (j == 10)
    {
      cout << -1;
      return;
    }
  }
  printf("%d",a);
  for (i = 0 ; i < n ;i ++)
    printf("%d",ans[i]);
}

int main()
{
  while(~scanf("%d%d%d\n",&a,&b,&n)) work();
  return 0;
}