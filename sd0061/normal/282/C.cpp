#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <cctype>
#include <queue>
#include <cstdio>
#include <utility>
#include <map>
#include <algorithm>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define LL long long
#define N 1000005
using namespace std;
int n , m;
char s[N] , t[N];
void work()
{
  bool f1 = 0 , f2 = 0;
  scanf("%s\n%s", s , t);
  n = strlen(s) , m = strlen(t);
  if (n != m) {puts("NO");return;}
  for (int i = 0 ; i < n ; ++ i)
    if (s[i] == '1')
    {
      f1 = 1;
      break;
    }
  for (int i = 0 ; i < n ; ++ i)
    if (t[i] == '1')
    {
      f2 = 1;
      break;
    }
  if (f1 == f2) printf("YES");
  else puts("NO");
}

int main()
{
  //while (~scanf("%s" , s + 1) , s[1] != '*')
  work();
  return 0;
}