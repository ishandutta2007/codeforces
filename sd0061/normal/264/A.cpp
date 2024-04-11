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
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
#define N 1000005
int n;
char s[N];
void work()
{
  gets(s), n = strlen(s);
  for (int i = 0 ; i < n ; ++ i)
    if (s[i] == 'r')
      printf("%d\n",i + 1);
  for (int i = n - 1 ; i >= 0 ; -- i)
    if (s[i] == 'l')
      printf("%d\n",i + 1);
}

int main()
{
  work();
  return 0;
}