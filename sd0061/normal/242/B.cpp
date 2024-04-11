#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 100005

int n , x = 1 << 30, y = -1 << 30;
struct sug
{
  int l , r;     
}s[N];
int main()
{
  int i ;
  cin >> n;
  for (i = 1 ;i <= n; i ++)
  {
    scanf("%d %d",&s[i].l , &s[i].r);
    x = min(s[i].l,x) , y = max(s[i].r,y);  
  }
  for (i = 1 ;i <= n; i ++)
    if (s[i].l == x && s[i].r == y)
    {
      printf("%d\n",i);
      break;         
    }
  if (i > n)
    cout << -1 << endl;  
  return 0;    
}