#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <cstdio>
#include <algorithm>
#define N 100005
using namespace std;
int n ;
long long lk , rk;
struct line
{
  long long k , b;   
}l[N];
long long k[N];
bool cmp(line x , line y)
{
  if (x.k * y.k > 0)
    return x.b * y.k - x.k * y.b > 0;
  return x.b * y.k - x.k * y.b < 0;  
}
int main()
{
  cin >> n; 
  int i , ans;
  for (i = 1 ;i <= n ;i ++)
  {
    cin >> l[i].k >> l[i].b;
    if (!l[i].k)
    { 
      i -- , n --;
      continue;
    }
    if (l[i].k < 0)
       lk += l[i].k; 
  }
  sort(l + 1 , l + 1 + n , cmp);
  k[0] = lk;
  ans = n;
  for (i = 1 ; i <= n ;i ++)
  {
    if (l[i].k > 0)
      rk += l[i].k;  
    if (l[i].k < 0)
      lk -= l[i].k; 
    k[i] = lk + rk;
    if (i != 1 && l[i].k * l[i - 1].b == l[i - 1].k * l[i].b )
      ans --;
    else if (k[i] == k[i - 1])
      ans --;     
  }
  cout << ans << endl;
  return 0;
}