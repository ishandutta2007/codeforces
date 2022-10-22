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
#define N 100005
int ans , n , a[N];
void work()
{
  int i;
  cin >> n;
  for (i = 1 ; i <= n ;i ++)
    cin >> a[i];
  ans = n + n - 1 + a[1];
  for (i = 2 ; i <= n; i ++)
    ans += abs(a[i] - a[i - 1]);
  cout << ans << endl;
}

int main()
{
  work();
  return 0;
}