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
#include <map>
#include <set>
#include <list>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
//#pragma comment(linker, "/STACK:16777216")
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define N 100005

int n , a[N];
void work()
{
  int i , x = 0 , y = 0;
  scanf("%d",&n);
  for (i = 1 ; i <= n ; ++ i)
    scanf("%d",&a[i]) , x = __gcd(x , a[i]) , y = max(a[i] , y);
  puts((y / x + n) & 1 ? "Alice" : "Bob");
}

int main()
{
  //while (~scanf("%d",&n))
  //int _; scanf("%d",&_); while (_--)
    work();
  return 0;
}