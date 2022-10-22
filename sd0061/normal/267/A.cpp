


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
#define N 20005
using namespace std;
int n , ans , a , b;

void work()
{
  scanf("%d%d",&a,&b);
  ans = 0;
  int x;
  while (a && b)
  {
    if (a < b) swap(a , b);
    if (a % b == 0)
    {
      ans += a / b;
      break;
    }
    else
    {
      x = a - b;
      x = x / b + ((x % b) != 0);
      ans += x , a -= x * b;
    }
  }
  cout << ans << endl;
}

int main()
{
  scanf("%d",&n);
  while (n --)
    work();
  return 0;
}