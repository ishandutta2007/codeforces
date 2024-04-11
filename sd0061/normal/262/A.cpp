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
#define N 20005
using namespace std;
int n , k , ans;

void work()
{
  scanf("%d%d",&n,&k);
  for (int i = 1 ; i <= n ;i ++)
  {
    int x , y , p = 0;
    scanf("%d",&x);
    while (x)
    {
      if (x % 10 == 4 || x % 10 == 7)
        ++ p;
      x /= 10;
    }
    if (p <= k)
      ++ ans;
  }
  cout << ans << endl;
}

int main()
{
  work();
  return 0;
}