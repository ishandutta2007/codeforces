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
int n; long long m ;
set<long long> h;

void work()
{
  int i , j ; long long x ,y  , ans = 0;
  scanf("%d%I64d",&n,&m);
  for (i = 1 ;i <= n ;i ++)
    scanf("%I64d",&x) , h.insert(x);
  if (m == 1) {cout << n << endl; return;}
  while (!h.empty())
  {
    x = *h.begin() , j = 1 , y = x;
    while (h.count((long long)x * m))
      x *= m , ++ j;
    ans += ((j + 1) >> 1);
    while (h.count(y))
      h.erase(y) , y *= m;
  }
  cout << ans << endl;
}

int main()
{
  //int _;cin>>_;while(_--)
  work();
  return 0;
}