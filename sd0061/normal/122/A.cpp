#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define LL long long
#define N 205
int n;

bool check(int x)
{
  char s[10];
  sprintf(s , "%d" , x);
  for (int i = 0 ; s[i] ; ++ i)
    if (s[i] != '4' && s[i] != '7')
      return 0;
  return 1;
}

void work()
{
  cin >> n; int i;
  for (i = 1 ; i <= n ; ++ i) if (check(i) && n % i == 0)
    break;
  puts(i <= n ? "YES" : "NO");
}

int main()
{
//  freopen("input.txt", "r" , stdin);
    work();
  return 0;
}