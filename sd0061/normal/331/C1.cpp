#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <queue>
#include <stack>
#include <utility>
#include <set>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define N 1000005
int n , m;
int f[N];

int F(int x)
{
  if (x == 0) return 0;
  if (f[x]) return f[x];
  int y = x;
  f[x] = 1 << 30;
  while (y)
    f[x] = min(f[x] , F(x - y % 10)) , y /= 10;
  return ++ f[x];
}


void work()
{
  int i;
  while (cin >> i)
    cout <<F(i) <<endl;
}

int main()
{
  //freopen("~input.txt","r",stdin);
  //while (~scanf("%d",&m))
  //int _; cin >> _;while (_--)
    work();
  return 0;
}