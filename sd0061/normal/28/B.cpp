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
#define N 205
#define LL long long
int n , d[N] , p[N] , f[N];
int getf(int x) {return x == f[x] ? x : f[x] = getf(f[x]);}


void work()
{
  int i;
  scanf("%d",&n);
  for (i = 1 ; i <= n ; ++ i) scanf("%d",&p[i]) , f[i] = i;
  for (i = 1 ; i <= n ; ++ i)
  {
    scanf("%d",&d[i]);
    if (i - d[i] > 0)
      f[getf(i)] = getf(i - d[i]);
    if (i + d[i] <= n)
      f[getf(i)] = getf(i + d[i]);
  }
  for (i = 1 ; i <= n ; ++ i)
    if (getf(i) != getf(p[i]))
      break;
  puts(i <= n ? "NO" : "YES");

}


int main()
{
 // freopen("~input.txt","r",stdin);
  //freopen("~output.txt","w",stdout);
//  int _; cin >> _; while (_ --)
    work();
  return 0;
}