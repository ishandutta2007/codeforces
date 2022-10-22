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
#define N 100005
char s[N] , t[N];
int ans , n , m;
void work()
{
  scanf("%s%s",s , t);
  n = strlen(s) , m = strlen(t);
  for (int i = 0 ; i < m ; ++ i)
    if (t[i] == s[ans])
      ++ ans;
  cout << ans + 1 << endl;
}

int main()
{
  work();
  return 0;
}