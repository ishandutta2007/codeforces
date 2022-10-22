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
#include <set>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
#define N 2005
typedef long long LL;
int n , k , ans = -1<<30;

void work()
{
  int i , x , y;
  scanf("%d%d",&n,&k);
  for (i = 0 ;i < n ;i ++)
  {
    scanf("%d%d",&x,&y);
    if (y > k) ans = max(ans , x - y + k);
    else ans = max(ans , x);
  }
  cout << ans << endl;
}

int main()
{
  //while (scanf("%d%d",&n ,&m) , n || m)
    work();
  return 0;
}