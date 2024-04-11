#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <string>
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
#define M 100005
#define LL long long
int n , a[N];
bool f[N];
void work()
{
  int i , s , t , ans = 0;
  scanf("%d%d%d",&n,&s,&t);
  for (i = 1 ; i <= n ; ++ i)
    scanf("%d",&a[i]);
  f[s] = 1;
  while (s != t)
  {
    s = a[s];
    if (f[s]) break;
    f[s] = 1 , ++ ans;
  }
  if (s != t) printf("-1");
  else printf("%d", ans);
}


int main()
{
  //init();
  //int _;cin>>_;while(_--)
  //while(~scanf("%d%d",&n,&m) , n || m)
    work();
  return 0;
}