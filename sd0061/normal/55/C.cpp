#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <map>
#include <string>
#include <utility>
#define mp make_pair
#define pb push_back
#define N 2505
using namespace std;
int n , m;
int dis;
void work()
{
  int i , x , y;
  dis = 1 << 30;
  cin >> n >> m >> i;
  while (i --)
  {
    cin >> x >> y;
    dis = min(dis , min(x - 1 , n - x));
    dis = min(dis , min(y - 1 , m - y));
  }
  puts(dis <= 4 ? "YES" : "NO");
}

int main()
{
  work();
  return 0;
}