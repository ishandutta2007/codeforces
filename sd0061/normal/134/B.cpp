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
int n , ans;

void dfs(int d , int x , int y)
{
  if (x < y) swap(x , y) ;
  if (x == y)
  {
    if (x == 1)
      ans = min(ans , d);
    return;
  }
  dfs(d + 1 , x - y , y);

}

void work()
{
  cin >> n;
  ans = 1 << 30;
  for (int i = 1 ; i <= n ; ++ i)
    dfs(0 , n , i);
  cout << ans << endl;
}


int main()
{
 // freopen("~input.txt","r",stdin);
 // freopen("~output.txt","w",stdout);
//  int _; cin >> _; while (_ --)
    work();
  return 0;
}