#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <cstdio>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#define N 100005
typedef long long LL;
#define fi first
#define se second
using namespace std;
int n , m;
int a[N] , s[N] , temp[N];
int sa[N] , t1[N] , t2[N] , c[N] , L[N];
int rank[N] , height[N];
void buildsa(int m)
{
  int i , k , *x = t1 , *y = t2;
  for (i = 0 ; i < m ; ++ i) c[i] = 0;
  for (i = 0 ; i < n ; ++ i) ++ c[x[i] = s[i]];
  for (i = 1 ; i < m ; ++ i) c[i] += c[i - 1];
  for (i = n - 1 ; i >= 0 ; -- i) sa[-- c[x[i]]] = i;
  for (k = 1 ; k <= n ; k <<= 1)
  {
    int p = 0;
    for (i = n - k ; i < n ; ++ i) y[p ++] = i;
    for (i = 0 ; i < n ; ++ i) if (sa[i] >= k) y[p ++] = sa[i] - k;
    for (i = 0 ; i < m ; ++ i) c[i] = 0;
    for (i = 0 ; i < n ; ++ i) ++ c[x[y[i]]];
    for (i = 1 ; i < m ; ++ i) c[i] += c[i - 1];
    for (i = n - 1 ; i >= 0 ; -- i) sa[-- c[x[y[i]]]] = y[i];
    swap(x , y) , p = 1 , x[sa[0]] = 0;
    for (i = 1 ; i < n ; ++ i)
      x[sa[i]] = (y[sa[i-1]] == y[sa[i]] && y[sa[i-1]+k] == y[sa[i]+k]) ? p - 1 : p ++;
    if (p >= n) break;
    m = p;
  }
  k = 0;
  for (i = 0 ; i < n ; ++ i) rank[sa[i]] = i;
  for (i = 0 ; i < n ; ++ i)
  {
    if (k) -- k; if (!rank[i]) continue;
    int j = sa[rank[i] - 1];
    while (s[i + k] == s[j + k]) ++ k;
    height[rank[i]] = k;
  }
}
vector<int> e[N];
int f[N][17];
vector< pair<int , int> > ans;

void work()
{
  int i , j , k , x , y , l;
  scanf("%d",&n);
  for (i = 0 ; i < n ; ++ i)
    scanf("%d",&s[i]) , a[i] = temp[i] = s[i];
  sort(a , a + n) , m = unique(a , a + n) - a;
  for (i = 0 ; i < n ; ++ i)
    s[i] = lower_bound(a , a + m , s[i]) - a + 1 , e[s[i]].push_back(i);
  s[n ++] = 0;
  buildsa(++ m);
  -- n , -- m;
  for (i = 1 ;i <= n ;i ++)
    f[i][0] = height[i];
  for (j = 1 ; 1 << j <= n ;j ++)
    for (i = 1 ;i + (1 << j) <= n ;i ++)
      f[i][j] = min(f[i][j - 1] , f[i + (1 << (j - 1))][j - 1]);
  for (i = 1 ; i <= m ; ++ i)
  {
    for (j = 0 ; j < e[i].size() ; ++ j)
      for (k = j + 1 ; k < e[i].size() ; ++ k)
      {
        x = rank[e[i][j]] , y = rank[e[i][k]];
        if (x > y) swap(x , y); ++ x;
        l = int (floor(log2(y - x + 1)));
        l = min(f[x][l] , f[y - (1 << l) + 1][l]);
        if (e[i][k] - e[i][j] <= l)
          ans.push_back( make_pair(e[i][k] - e[i][j] , e[i][j]) );
      }
  }
  sort(ans.begin() , ans.end());
  int tmp = 0;
  for (i = 0 ; i < ans.size() ; ++ i)
  {
    x = ans[i].first , y = ans[i].second;
    if (y >= tmp) tmp = max(tmp , x + y);
  }
  cout << n - tmp << endl;
  for (i = tmp ; i < n ; ++ i)
    printf("%d " , temp[i]);
}

int main()
{
  work();
  return 0;
}