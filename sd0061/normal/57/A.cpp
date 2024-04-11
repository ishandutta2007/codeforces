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
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
#define N 100005
int n , a , b , c , d;

void work()
{
  int x , y;
  scanf("%d",&n);
  cin >> a >> b;
  if (a == 0)
    x = b;
  else if (a == n)
    x = 3 * n - b;
  else if (b == 0)
    x = 4 * n - a;
  else x = n + a;
  cin >> a >> b;
  if (a == 0)
    y = b;
  else if (a == n)
    y = 3 * n - b;
  else if (b == 0)
    y = 4 * n - a;
  else y = n + a;
  if (x > y) swap(x , y);
  cout << min(y - x , 4 * n - y + x);
}

int main()
{
  work();
  return 0;
}