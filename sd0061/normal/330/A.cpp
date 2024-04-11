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
#include <list>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
//#pragma comment(linker, "/STACK:16777216")
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define N 105
int n , m;
char s[N][N];
bool r[N] , c[N];

void work()
{
  int i , j;
  scanf("%d%d",&n,&m);
  for (i = 1 ; i <= n; ++ i)
    scanf("%s" , s[i] + 1);
  for (i = 1 ; i <= n ; ++ i)
    for (j = 1 ; j <= m ; ++ j)
      r[i] |= (s[i][j] == 'S') , c[j] |= (s[i][j] == 'S');
  int ans = 0;
  for (i = 1 ; i <= n ; ++ i)
    for (j = 1 ; j <= m ; ++ j)
      ans += !(r[i] && c[j]);
  cout << ans << endl;
}

int main()
{
  std::ios::sync_with_stdio(false);
  //while (~scanf("%d",&n))
    work();
  return 0;
}