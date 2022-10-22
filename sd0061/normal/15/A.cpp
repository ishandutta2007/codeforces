#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <cstdio>
#include <set>
#include <map>
#include <algorithm>
#define N 100005
typedef long long LL;
using namespace std;
int n , t;
pair<int , int> a[N];


void work()
{
  int i , j;
  cin >> n >> t;
  for (i = 0 ; i < n ; ++ i)
    cin >> a[i].first >>  a[i].second;
  sort(a , a + n);
  int ans = 2;
  for (i = 0 ; i < n - 1 ; ++ i)
  {
    if (2 * (a[i + 1].first - a[i].first) - (a[i].second + a[i + 1].second) == t * 2)
      ++ ans;
    else if (2 * (a[i + 1].first - a[i].first) - (a[i].second + a[i + 1].second) > t * 2)
      ans += 2;
  }
  cout << ans;
}


int main()
{
//  while (scanf("%d",&n) , n)
  //int _; cin >> _; while (_--)
    work();
  return 0;
}