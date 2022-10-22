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
#define N 100002
#define L 1002

void work()
{
  int n;
  scanf("%d",&n);
  for (n = n + 1 ; ; n ++)
  {
    char s[6];
    sprintf(s, "%d" , n);
    sort(s , s + 4);
    if (s[0] != s[1] && s[1] != s[2] && s[3] != s[2])
    {
      cout << n;
      return;
    }
  }
}

int main()
{
 // freopen("~input.txt","r",stdin);
 // freopen("~output.txt","w",stdout);
  work();
  return 0;
}