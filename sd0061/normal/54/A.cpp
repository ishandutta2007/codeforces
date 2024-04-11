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
#define N 3005
#define LL long long


void work()
{
  int n , k , c , t , s = 0 , last = 0;
  scanf("%d%d%d",&n,&k,&c);
  for (int i = 0 ; i < c ; ++ i)
  {
    scanf("%d",&t);
    s += (t - last - 1) / k + 1;
    last = t;
  }
  s += (n - last) / k;
  printf("%d\n",s);
}

int main()
{
  work();
  return 0;
}