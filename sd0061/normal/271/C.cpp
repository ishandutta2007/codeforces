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
#define N 1000005
#define M 502
int n , k , p[N];

void work()
{
  int i ;
  cin >> n >> k;
  if (k * 3 > n)
  {
    cout << -1;
    return;
  }
  for (i = 2; i <= k; i ++)
    cout << i << " ";
  cout << 1 << " ";
  for (i = k; i < n; i ++)
    cout << i % k + 1<< " ";
}

int main()
{
  work();
  return 0;
}