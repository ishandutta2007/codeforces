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
int f[101][N];
const int Q = 1e9 + 7;
char s[101];
void work()
{
  int i , j , k;
  f[0][0] = 1;
  for (i = 1 ; i <= 100 ; ++ i)
    for (j =  0 ; j <= 2500 ; ++ j)
      for (k = 0 ; k < 26 ; ++ k) if (j - k >= 0)
        f[i][j] += f[i - 1][j - k] , f[i][j] %= Q;
  scanf("%d",&m);
  while (m --)
  {
    scanf("%s" , s);
    n = strlen(s);
    j = 0;
    for (i = 0 ; i < n ; ++ i) j += s[i] - 'a';
    cout << f[n][j] - 1 << endl;
  }
}

int main()
{
  work();
  return 0;
}