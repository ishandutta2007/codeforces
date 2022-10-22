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
#define pb push_back
#define mp make_pair
#define fi first
#define se second
//#pragma comment(linker, "/STACK:16777216")
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define N 1050005
int n , a[N];
LL s[N] , ans;

void work()
{
  int i ; LL j;
  cin >> n;
  for (i = 0 ; i < n ; ++ i)
    scanf("%d" , &a[i]);
  sort(a , a + n , greater<int>());
  s[0] = a[0];
  for (i = 1 ; i < n ; ++ i)
    s[i] = s[i - 1] + a[i];
  for (j = 1 ; j <= n ; j <<= 2)
    ans += s[j - 1];
  cout << ans << endl;
}

int main()
{
    work();
  return 0;
}