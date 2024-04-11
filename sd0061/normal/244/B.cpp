#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;
#define N 100005
long long n;
int len , ans;
map<int,bool> h;
void dfs(int x ,int y ,long long num ,int dep)
{
  if (num <= n && num && !h.count(num))
    h[num] = 1 , ans ++ ;
  if (dep > len)
    return;         
  if (num != 0 || (num == 0 && x != 0))
    dfs(x , y , num * 10 + x , dep + 1);
  if (num != 0 || (num == 0 && y != 0))
    dfs(x , y , num * 10 + y , dep + 1);
}

int main()
{
  int x , y;long long i;
  cin >> n;
  for (len = 0 , i = 1 ; i <= n ; len ++ , i *= 10);
  for (x = 0 ; x < 10 ; x ++)
    for (y = x + 1 ; y < 10 ; y ++)
      dfs(x , y , 0 , 1);
  cout << ans << endl;    
  return 0;    
}