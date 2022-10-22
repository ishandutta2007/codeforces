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
#include <set>
#define N 1002
using namespace std;
long long f[N] , s;
int k;
vector<long long> ans;
void work()
{
  int i , j;
  cin >> s >> k;
  f[1] = 1;
  for (i = 2 ;  ; ++ i)
  {
    for (j = 1 ; i >= j && j <= k ; ++ j)
      f[i] += f[i - j];
    if (f[i] >= 1LL << 32) break;
  }
  for ( ; i > 0 ; -- i)
  {
    if (s >= f[i])
    {
      s -= f[i] , ans.push_back(f[i]);
    }
  }
  if (ans.size() < 2) ans.resize(2);
  printf("%d\n" , ans.size());
  for (i = 0 ; i < ans.size() ; ++ i)
    printf("%d " , ans[i]);
}

int main()
{
    work();
  return 0;
}