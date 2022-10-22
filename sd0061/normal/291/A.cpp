#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
int n;
map<int , int> a;

void work()
{
  int i , x , ans = 0;
  scanf("%d",&n);
  for (i = 1 ; i <= n ; ++ i)
    scanf("%d",&x) , ++ a[x];
  map<int,int>::iterator it;
  for (it = a.begin() ; it != a.end() ; ++ it)
    if (it -> first)
    {
      x = it -> second;
      if (x > 2) break;
      if (x == 2) ans ++;
    }
  if (it != a.end())
    ans = -1;
  cout << ans << endl;
}

int main()
{
  work();
  return 0;
}