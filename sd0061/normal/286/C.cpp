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
#define N 2000005
#define LL long long
int n , a[N] , ans[N];
bool f[N];

void work()
{
  int i , x;
  scanf("%d",&n);
  for (i = 1 ; i <= n ;i ++)
    scanf("%d",&a[i]);
  scanf("%d",&x);
  while (x --)
    scanf("%d" , &i) , f[i] = 1;
  stack<int> s;
  for (i = n ; i > 0 ; -- i)
    if (f[i])
    {
      ans[i] = -a[i];
      s.push(a[i]);
    }
    else if (!s.empty() && a[i] == s.top())
    {
      ans[i] = a[i];
      s.pop();
    }
    else
    {
      ans[i] = -a[i];
      s.push(a[i]);
    }
  if (s.size()) {puts("NO");return;}
  puts("YES");
  for (i = 1 ; i <= n ;i ++)
    printf("%d " , ans[i]);
}

int main()
{
  work();
  return 0;
}