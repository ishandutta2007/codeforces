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
int n , m ;
vector<int> ans;
char s[N];
int main()
{
  int i , j;
  scanf("%d%d\n%s",&n,&m,s);
  while (m --)
  {
    ans.clear();
    for (i = 1 ;i < n ; i ++)
      if (s[i - 1] == 'B' && s[i] == 'G')
        ans.push_back(i);
    for (i = 0 ;i < ans.size() ; ++ i)
      j = ans[i] , swap(s[j - 1] , s[j]);
  }
  for (i = 0 ;i < n ; i ++)
    printf("%c",s[i]);
  return 0;
}