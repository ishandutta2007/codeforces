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
#define N 2005
int n , m , k;
int f[N][N] , Q = 1e9 +7;
void work()
{
  int i , j;
  cin >> n >> m >> k;
  -- n , -- m;
  for (i = 0 ; i <= max(n , m) ; ++ i)
  {
    f[i][0] = 1;
    for (j = 1 ; j <= i ; ++ j)
      f[i][j] = (f[i - 1][j] + f[i - 1][j - 1]) % Q;
  }
  cout << (LL) f[n][k << 1] * f[m][k << 1] % Q << endl;

}

int main()
{
    work();
  return 0;
}