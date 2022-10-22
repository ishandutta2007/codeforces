#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <cstdio>
#include <set>
#include <map>
#include <algorithm>
#define N 100005
typedef long long LL;
using namespace std;
int n ;
LL X[N] , Y[N];
void work()
{
  int i ; LL ans = 0 , x , y;
  scanf("%d",&n);
  for (i = 1 ; i <= n ; ++ i)
    cin >> X[i] >> Y[i];
  for (i = 1 ; i <= n ; ++ i)
  {
    //X[i] ~ X[i] + Y[i]- 1
    x = X[i] + Y[i] - 1;
    if (x % 4 == 0) ans ^= x;
    if (x % 4 == 1) ans ^= 1;
    if (x % 4 == 2) ans ^= x + 1;
    if (x % 4 == 3) ans ^= 0;
    x = X[i] - 1;
    if (x % 4 == 0) ans ^= x;
    if (x % 4 == 1) ans ^= 1;
    if (x % 4 == 2) ans ^= x + 1;
    if (x % 4 == 3) ans ^= 0;
  }
  puts(ans ? "tolik" : "bolik");
}


int main()
{
  //int _; cin >> _; while (_--)
    work();
  return 0;
}