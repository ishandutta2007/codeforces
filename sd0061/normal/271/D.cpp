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
#define N 1502
int n , k , ans;
char s[N] , f[26] ;

struct trie
{
  int sum;
  int u[N * N][26];
  int v[N * N];
  void clear()
  {
    sum = 1;
    memset(u[0] , 0 , sizeof(u[0]));
  }
  void insert(char *str)
  {
    int x = 0 , p = strlen(str) , q = 0;
    for (int i = 0 ; i < p ; i ++)
    {
      int c = str[i] - 'a';
      if (q == k && f[c] == '0') return;
      if (f[c] == '0') ++ q;
      if (!u[x][c])
      {
        memset(u[sum] , 0 , sizeof(u[sum]));
        v[sum] = 0;
        u[x][c] = sum ++;
      }
      x = u[x][c];
      if (!v[x]) v[x] = 1 , ++ ans;
    }
    //if (!v[x]) v[x] = 1 , ++ ans;
  }
}t;

void work()
{
  scanf("%s\n%s\n%d",s , f, &k);
  n = strlen(s) , t.clear();
  for (int i = 0 ; i < n ; ++ i)
    t.insert(s + i);
  cout << ans << endl;
}

int main()
{
  work();
  return 0;
}