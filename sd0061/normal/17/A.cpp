#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <cstdio>
#include <set>
#include <map>
#include <algorithm>
#define N 1005
typedef long long LL;
using namespace std;
int n , k;
bool f[N] , add[N];
void work()
{
  int i , j , s = 0;
  cin >> n >> k;
  for (i = 2 ; i * i <= n ; ++ i) if(!f[i])
    for (j = i * i ; j <= n ; j += i) f[j] = 1;
  for (i = 2 ; i <= n ; ++ i) if (!f[i])
    for (j = i + 1 ; i + j + 1 <= n ; ++ j) if (!f[j])
    {
      add[i + j + 1] = 1;
      break;
    }
  for (i = 2 ; i <= n ; ++ i)
    s += add[i] && !f[i];
  puts(s >= k ? "YES" : "NO");
}


int main()
{
//  while (scanf("%d",&n) , n)
  //int _; cin >> _; while (_--)
    work();
  return 0;
}