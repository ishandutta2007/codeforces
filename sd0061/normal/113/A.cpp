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
#define N 100005
#define LL long long
char name[6][10] = {"lios", "etr" , "initis" , "liala" , "etra" , "inites"};
int check(char *s)
{
  int len = strlen(s) , i , j , k;
  for (i = 0 ; i < 6 ; ++ i)
  {
    for (j = len - strlen(name[i]) , k = 0 ; j != len ; ++ j , ++ k)
      if (s[j] != name[i][k])
        break;
    if (j == len) return i;
  }
  return -1;
}
char str[N] ;
int n, type[N];

void work()
{
  int i , j , gender;
  while (~scanf("%s" , str))
  {
    ++ n , i = check(str);
    if (i == -1)
    {
      puts("NO");
      return;
    }
    if (n == 1)
      gender = i / 3;
    if (i / 3 != gender)
    {
      puts("NO");
      return;
    }
    type[n] = i % 3;
  }
  if (n == 1)
  {
      puts("YES");
      return;
  }
  int a , b , c;
  for (i = 1 ; i <= n ; ++ i)
    if (type[i] != 0)
    {
      a = i;
      break;
    }
  for (i = n ; i > 0 ; -- i)
    if (type[i] != 2)
    {
      b = i;
      break;
    }
  if (a != b)
  {
    puts("NO");
    return;
  }
  if (type[a] == 1)
    puts("YES");
  else puts("NO");

}


int main()
{
    work();
  return 0;
}