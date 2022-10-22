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
#define N 105
#define LL long long
LL a , b , m;
void work()
{
  LL i , j = 0;
  cin >> a >> b >> m;
  for (i = 1 ; i <= min(a , m) ; ++ i)
  {
    j = (j - 1000000000 % m + m) % m;
    if (b < j) break;
  }
  if (i > min(a , m))
    puts("2");
  else
    printf("1 %09d" , (int)i);
}

int main()
{
  work();
  return 0;
}