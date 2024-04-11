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
#define fi first
#define se second
using namespace std;
#define N 4200005
struct trie
{
  int sum;
  int u[N][2];
  long long v[N];
  void clear()
  {
    sum = 1;
    memset(u[0] , 0 , sizeof(u[0]));
  }
  void insert(int *str , long long val)
  {
    int x = 0;
    for (int i = 0 ; i < 40 ; i ++)
    {
      int c = str[i];
      if (!u[x][c])
      {
        memset(u[sum] , 0 , sizeof(u[sum]));
        v[sum] = 0;
        u[x][c] = sum ++;
      }
      x = u[x][c];
    }
    v[x] = val;
  }
  long long find(int *str , long long val)
  {
    int x = 0;
    for (int i = 0 ; i < 40 ; i ++)
    {
      int c = str[i];
      if (u[x][c])
        x = u[x][c];
      else
        x = u[x][!c];
    }
    return val ^ v[x];
  }
}t;
 int n ;
 long long s[N];

void work()
{
  int i  , j; long long p = 0 , q = 0 , x , ans = 0;
  t.clear(); int a[41] = {};
  scanf("%d",&n);
  for (i = 1 ; i <= n ;i ++)
    scanf("%I64d", &s[i]) , p ^= s[i];
  ans = 0;
  t.insert(a , 0);
  for (i = n ; i > 0 ; -- i)
  {
    x = p;
    for (j = 0 ; j < 40 ; ++ j)a[j] = !(x & 1) , x >>= 1;reverse(a , a + 40);
    ans = max(ans , t.find(a , p));
    p ^= s[i] , q ^= s[i];
    x = q;
    for (j = 0 ; j < 40 ; ++ j)a[j] = x & 1 , x >>= 1;reverse(a , a + 40);
    t.insert(a , q);
  }
  for (j = 0 ; j < 40 ; ++ j) a[j] = 1;
  ans = max(ans , t.find(a , 0));

  cout << ans << endl;
}

int main()
{
  work();
  return 0;
}