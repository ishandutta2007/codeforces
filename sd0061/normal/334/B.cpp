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
#include <map>
#include <set>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
//#pragma comment(linker, "/STACK:16777216")
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define N 15
pair<int , int> a[N];
pair<int , int> b[N];
void work()
{
  int n , i;
  n = 8;
  for (i = 0 ; i < n ; ++ i)
    cin >> a[i].fi >> a[i].se;
  sort(a , a + n);
  int x1 , x2 , x3 , y1 , y2 , y3;
  x1 = a[0].fi , x2 = a[3].fi , x3 = a[5].fi;
  y1 = a[0].se , y2 = a[1].se , y3 = a[2].se;
  if (x1 >= x2 || x2 >= x3 || x1 >= x3 || y1 >= y2 || y1 >= y3 || y2 >= y3)
  {
    puts(1 ? "ugly" : "respectable");
    return;
  }

  i = 0;
  b[i ++] = make_pair(x1 , y1);
  b[i ++] = make_pair(x1 , y2);
  b[i ++] = make_pair(x1 , y3);
  b[i ++] = make_pair(x2 , y1);
  b[i ++] = make_pair(x2 , y3);
  b[i ++] = make_pair(x3 , y1);
  b[i ++] = make_pair(x3 , y2);
  b[i ++] = make_pair(x3 , y3);
  for (i = 0 ; i < n ; ++ i)
    if (a[i] != b[i])
      break;
  puts(i < n ? "ugly" : "respectable");

}

int main()
{
     work();
  return 0;
}