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
#define fi first
#define se second
using namespace std;
#define N 105
int n , k , a , ans;

void work()
{
  cin >> n;
  while (n --)
  {
    cin >> k >> a;
    if (a == 1) ++ k;
    while (a > 1)
      ++ k , a = (a >> 2) + ((a & 3) != 0);
    ans = max(ans, k);
  }
  cout << ans;
}

int main()
{
  work();
  return 0;
}