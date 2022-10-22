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
#define N 105
#define LL long long
int n , m , k1 , k2;
int f[N][N][12][12] , Q = 1e8;

int cal(int n1, int n2, int x1, int x2)
{
  if (n1 == 0 && n2 == 0)
    return 1;

  int &a = f[n1][n2][x1][x2];
  if (a != -1)
    return a;
  a = 0;
  if (n1 > 0 && x1 < k1)
    a += cal(n1 - 1, n2, x1 + 1, 0);
  if (n2 > 0 && x2 < k2)
    a += cal(n1, n2 - 1, 0, x2 + 1);
  return a %= Q;
}

void work()
{
  memset(f , -1 , sizeof(f));
  cin >> n >> m >> k1 >> k2;
  cout << cal(n , m , 0 , 0) << endl;

}

int main()
{
  work();
  return 0;
}