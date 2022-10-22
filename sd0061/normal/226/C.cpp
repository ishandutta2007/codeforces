#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
typedef long long LL;
LL l , r , m , k;
vector<LL> divt;

struct matrix
{
  LL m[2][2];     
};
matrix operator * (matrix a , matrix b)
{
  matrix ans;
  for (int i = 0 ; i < 2 ;i ++)
    for (int j = 0 ; j < 2 ;j ++)
    {
      ans.m[i][j] = 0;
      for (int k = 0 ;k < 2 ;k ++)
        ans.m[i][j] += a.m[i][k] * b.m[k][j] , ans.m[i][j] %= m;  
    }     
  return ans;  
}
int main()
{
  cin >> m >> l >> r >> k;
  for (LL d = 1 ;  d * d <= r ; ++ d)
    divt.push_back(d) , divt.push_back(r / d) ; 
  for (LL d = 1 ;  d * d <= l ; ++ d)
    if (l % d == 0)
      divt.push_back(l / d);
    else if (d)
      divt.push_back(l / (d - 1));
  LL ans = 0;
  for (int i = 0 ;i < divt.size() ; ++ i)
  {
    LL up = r / divt[i] , down = l / divt[i];
    if (l % divt[i] != 0) 
      ++ down;
    if (up - down + 1 >= k)
      ans = max(ans , divt[i]);   
  }      
  matrix fib , w;
  fib.m[0][0] = fib.m[1][1] = 1 , fib.m[0][1] = fib.m[1][0] = 0;
  w.m[0][0] = w.m[1][0] = w.m[0][1] = 1 , w.m[1][1] = 0;
  while (ans)
  {
    if (ans & 1LL)
      fib = fib * w;
    w = w * w;
    ans >>= 1;      
  }
  cout << fib.m[1][0] << endl;
  return 0;
}