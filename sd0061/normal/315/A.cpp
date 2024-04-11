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
pair<int , int> a[N];
int n , ans;
bool f[N];
void work()
{
  int i  , j;
  cin >> n ;
  for (i = 0 ; i < n ; ++ i) cin >> a[i].fi >> a[i].se;
  for (i = 0 ; i < n ; ++ i)
  {
    for (j = 0 ; j < n ; ++ j) if (i != j)
      if (a[j].se == a[i].fi)
        break;
    if (j >= n) ++ ans;
  }
  cout << ans << endl;

}


int main()
{

    work();
  return 0;
}