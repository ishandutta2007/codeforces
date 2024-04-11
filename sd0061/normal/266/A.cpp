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
#define N 100005
using namespace std;
int n , m , a[N];
char s[N];
int main()
{
  int i , ans = 0;
  scanf("%d\n%s\n",&n,s);
  for (i = 1 ;i < n ; i ++)
    if (s[i] == s[i - 1])
      ans ++;
  cout << ans << endl;
  return 0;
}