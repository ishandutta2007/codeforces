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
#include <map>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
#define N 200005
#define LL long long
int n , a[N] , k;

void work()
{
  int i , m , h; LL x , p;
  scanf("%d%d",&n,&k);
  for (i = 1 ; i <= n ; ++ i)
    scanf("%d",&a[i]);
  m = n , h = x = 0;
  for (i = 1 ; i <= n ; ++ i)
  {
    p = (LL)(m - i + h) * (i - h - 1) * -a[i];
    p += x;
    x += (LL)a[i] * (i - h - 1);
    if (p < k)
    {
      printf("%d\n" , i);
      x -= (LL)a[i] * (i - h - 1);
      -- m , ++ h;
    }
  }
}


int main()
{
 // freopen("~input.txt","r",stdin);
  //freopen("~output.txt","w",stdout);
//  int _; cin >> _; while (_ --)
    work();
  return 0;
}