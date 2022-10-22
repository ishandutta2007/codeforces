#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define N 200005
int n;
vector<int> a , b;
void work()
{
  int i , x , y , j , k , ans = 0 , sum = 0 ,cnt = 0;
  scanf("%d",&n);
  for (i = 1 ; i <= 2 * n - 1 ; ++ i)
  {
    scanf("%d",&x);
    if (x < 0)
      a.push_back(-x);
    else b.push_back(x);
    ans += x;
  }
  sort(a.begin() , a.end() , greater<int>());
  x = a.size() % 2;
  y = a.size() / 2 , k = y * 2;
  if (n & 1) x = 0;
  for (i = 0 ; i < a.size() - x ; ++ i)
    b.push_back(a[i]) , ans += a[i] << 1;
  sort(b.begin() , b.end());

  if (x)
  {
    cnt += a[a.size() - 1] << 1;
    cnt -= b[0] << 1;
  }
  if (cnt > 0) ans += cnt;
  cout << ans;
}

int main()
{
  //while(scanf("%s", s) , s[0] != '#')
  //int _;cin>>_;while(_--)
    work();
  return 0;
}