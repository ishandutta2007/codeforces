#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define LL long long
#define N 205
int x[8] , y[8];
vector<pair<int ,int> > h;
void work()
{
  int i , p , mx = -1 << 30, my = -1 << 30, nx = 1 << 30, ny = 1 << 30 ;
  for (i = 0 ;i < 8 ; ++ i)
    cin >> x[i] >> y[i] , h.push_back(make_pair(x[i] , y[i])) ,
    mx = max(x[i] , mx) , nx = min(x[i] , nx) ,
    my = max(y[i] , my) , ny = min(y[i] , ny) ;
  sort(h.begin() , h.end());
  if (unique(h.begin() , h.end()) - h.begin() != 4)
  {
    puts("NO");
    return;
  }
  if ((mx - nx) * (my - ny) == 0)
  {
    puts("NO");
    return;
  }

  for (i = 0 ; i < 4 ; ++ i)
  {
    if (x[i << 1] == mx && y[i << 1] == my && x[i << 1 | 1] == mx && y[i << 1 | 1] == ny) break;
    if (x[i << 1 | 1] == mx && y[i << 1 | 1] == my && x[i << 1] == mx && y[i << 1] == ny) break;
  }
  if (i >= 4)
  {
    puts("NO");
    return;
  }
  for (i = 0 ; i < 4 ; ++ i)
  {
    if (x[i << 1] == mx && y[i << 1] == my && x[i << 1 | 1] == nx && y[i << 1 | 1] == my) break;
    if (x[i << 1 | 1] == mx && y[i << 1 | 1] == my && x[i << 1] == nx && y[i << 1] == my) break;
  }
  if (i >= 4)
  {
    puts("NO");
    return;
  }
  for (i = 0 ; i < 4 ; ++ i)
  {
    if (x[i << 1] == nx && y[i << 1] == ny && x[i << 1 | 1] == mx && y[i << 1 | 1] == ny) break;
    if (x[i << 1 | 1] == nx && y[i << 1 | 1] == ny && x[i << 1] == mx && y[i << 1] == ny) break;
  }
  if (i >= 4)
  {
    puts("NO");
    return;
  }
  for (i = 0 ; i < 4 ; ++ i)
  {
    if (x[i << 1] == nx && y[i << 1] == ny && x[i << 1 | 1] == nx && y[i << 1 | 1] == my) break;
    if (x[i << 1 | 1] == nx && y[i << 1 | 1] == ny && x[i << 1] == nx && y[i << 1] == my) break;
  }
  if (i >= 4)
  {
    puts("NO");
    return;
  }
  puts("YES");
}

int main()
{
  work();
  return 0;
}