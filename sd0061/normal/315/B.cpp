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
#define N 100005
#define LL long long
LL a[N] , p;
int n , m;

void work()
{
  int i , j , x;
  scanf("%d%d",&n,&m);
  for (i = 1 ; i <= n ; ++ i)
    scanf("%I64d",&a[i]);
  while (m --)
  {
    scanf("%d%d",&i,&x);
    if (i == 1)
    {
      scanf("%d",&j);
      a[x] = j - p;
    }
    if (i == 2)
      p += x;
    if (i == 3)
      cout << a[x] + p << endl;
  }
}


int main()
{
    work();
  return 0;
}