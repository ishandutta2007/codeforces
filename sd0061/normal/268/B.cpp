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

#define N 40005
int n , ans , h[N] , a[N];


void work()
{
  int i , j;
  scanf("%d",&n);
  long long ans = 1;
  for (i = 2 ; i <= n ;i ++)
    ans += (i) + (((i - 2) * (i - 1)) >> 1);
  cout << ans << endl;
}

int main()
{
  //freopen("~input.txt","r",stdin);
  //freopen("~output.txt","w",stdout);
  work();
  return 0;
}