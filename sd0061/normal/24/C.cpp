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
int n ;
LL xx[N] , yy[N] , m;

void work()
{
  int i ; LL x , y;
  cin >> n >> m;
  cin >> x >> y;
  for (i = 0 ; i < n ; ++ i)
    cin >> xx[i] >> yy[i];
  m %= n << 1;
  for (i = 0 ; i < min((LL)n , m) ; ++ i)
    x = 2 * xx[i] - x , y = 2 * yy[i] - y;
  for (i = 0 ; i < m - n ; ++ i)
    x = 2 * xx[i] - x , y = 2 * yy[i] - y;
  cout << x << ' ' << y;

}


int main()
{
 // freopen("~input.txt","r",stdin);
 // freopen("~output.txt","w",stdout);
//  int _; cin >> _; while (_ --)
    work();
  return 0;
}