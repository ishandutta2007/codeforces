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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define N 100005

int n , m , a[N];
void work()
{
  int i;
  LL ans = 0;
  cin >> n >> m;
  for (i = 1 ; i <= m ; ++ i)
    cin >> a[i];
  a[0] = 1;
  for (i = 1 ; i <= m ; ++ i)
  {
    if (a[i] >= a[i - 1])
      ans += a[i] - a[i - 1];
    else ans += n + a[i] - a[i - 1];
  }
  cout << ans << endl;
}

int main()
{
 // freopen("~input.txt" , "r" , stdin);
  //while (~scanf("%d%d",&n,&K))
    work();
  return 0;
}