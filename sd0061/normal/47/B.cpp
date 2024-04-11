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
int n , m , k;
int d[N];
char str[N];
void work()
{
  int i , j ,  x , y;
  for (i = 1 ; i <= 3 ; ++ i)
  {
    scanf("%s", str);
    x = str[0] - 'A' , y = str[2] - 'A';
    if (str[1] == '<')
      ++ d[y];
    else ++ d[x];
  }
  for (i = 0 ; i < 3 ; ++ i)
  {
    for (j = 0 ; j < 3 ; ++ j)
      if (d[j] == i)
        break;
    if (j >= 3) break;
    printf("%c",'A' + j);
  }
  if (i < 3)
    puts("Impossible");
}

int main()
{
  work();
  return 0;
}