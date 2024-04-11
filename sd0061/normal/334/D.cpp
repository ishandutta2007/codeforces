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
#define N 1005
int n , m , ans;
bool r[N] , c[N];

void work()
{
  int i , x , y , j;
  cin >> n >> m;
  for (i = 1; i <= m ; ++ i)
  {
    scanf("%d%d",&x,&y);
    r[x] = c[y] = 1;
  }
  for (i = 2 ; i < n ; ++ i)
  {
    if (!r[i]) ++ ans;
    if (!c[i]) ++ ans;
  }
  if (n & 1)
  {
    i = n + 1 >> 1;
    if (!r[i] && !c[i])
      -- ans;
  }
  cout << ans << endl;
}

int main()
{
  //freopen("~input.txt","r",stdin);
  //while (~scanf("%d",&n))
    work();
  return 0;
}