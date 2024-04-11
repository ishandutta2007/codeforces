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
int n , fail[N] , ans , len , L;
string s[N];
char str[N * 3] , tmp[N];
vector<int> e[N];
/*
  for (int i = 0 ,j = 0 ; i < n ;i ++) {
    while (j && T[i] != P[j]) j = u[j];
    if (T[i] == P[j]) ++ j;
    if (j == m) printf("%d\n",i - m + 1);
  }
*/
void dfs(int x , int p)
{
  int i , j , tmplen = L;
  for (i = 0 ; i < s[x].size() ; ++ i)
  {
    str[L] = s[x][i];
    while (p && str[L] != tmp[p])
      p = fail[p];
    if (str[L] == tmp[p]) ++ p;
    if (p == len) ++ ans;
    ++ L;
  }
  for (i = 0 ;i < e[x].size() ; ++ i)
    dfs(e[x][i] , p);
  L = tmplen;
}

void work()
{
  int i , j , x;
  scanf("%d",&n);
  for (i = 2 ; i <= n ; ++ i)
  {
    scanf("%d",&x);
    cin >> s[i];
    e[x].push_back(i);
  }
  scanf("%s" , tmp);
  len = strlen(tmp);
  fail[0] = fail[1] = 0;
  for (i = 1 ; i < len ;i ++)
  {
    j = fail[i];
    while (j && tmp[i] != tmp[j]) j = fail[j];
    fail[i + 1] = tmp[i] == tmp[j] ? j + 1 : 0;
  }
  dfs(1 , 0);
  cout << ans << endl;
}


int main()
{
  work();
  return 0;
}