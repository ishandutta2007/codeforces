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
#define N 100005
using namespace std;
int n , m , ans;
int p[N] , q[N];
bool cmp(int x , int y) {return x > y;}
void work()
{
  int i , j , x , y;
  scanf("%d",&m);
  for (i = 1 ; i <= m ;i ++)
    scanf("%d",&q[i]);
  sort(q + 1, q + m + 1);
  scanf("%d",&n);
  for (i = 1 ; i <= n ;i ++)
    scanf("%d",&p[i]);
  sort(p + 1, p + n + 1 , cmp);
  for (i = 1 ; i <= n ;)
  {
    for (j = 0 ;j < q[1] && i + j <= n;j ++)
      ans += p[i + j];
    i += q[1] + 2;
  }

  cout << ans << endl;
}

int main()
{
  work();
  return 0;
}