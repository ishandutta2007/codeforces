#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <cctype>
#include <queue>
#include <cstdio>
#include <utility>
#include <map>
#include <algorithm>
#define fi first
#define se second
#define mp make_pair
#define N 100005
using namespace std;
int xx , yy;
void work()
{
  int t = 0 , x  , y , n = 1 , dx , dy;
  cin >> xx >> yy;
  x = y = 0;
  if (xx == 0 && yy == 0)
  {
    printf("0");
    return;
  }
  while (1)
  {
    ++ t;
    if (t % 4 == 1) dx = x , dy = y , x += n;
    if (t % 4 == 2) dx = x , dy = y , y += n;
    if (t % 4 == 3) dx = x , dy = y , x -= n;
    if (t % 4 == 0) dx = x , dy = y , y -= n;
    if (t % 2 == 0) ++ n;
    if (xx <= max(x , dx) && xx >= min(x , dx) && yy >= min(y , dy) && yy <= max(y , dy))
    {
      printf("%d",t - 1);
      return;
    }
  }
}

int main()
{
  //int _;cin>>_;while (_--)
  work();
  return 0;
}