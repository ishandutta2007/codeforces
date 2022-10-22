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
LL n , m , x , y , a , b;

void work()
{
  LL c , d , e , f , g , h;
  cin >> n >> m >> x >> y >> a >> b;
  if (x > a) swap(x , a) , swap(y , b);
  if (y > b)
    y = m - y + 1 , b = m - b + 1;
  c = min(n , x + n - a) , d = min(m , y + m - b);
  e = a - x + 1, f = b - y + 1;
  LL ans = n * m - c * d - (n - e + 1) * (m - f + 1);
  g = max(0LL , min(n , c) - max(1LL , e) + 1);
  h = max(0LL , min(m , d) - max(1LL , f) + 1);
  ans += g * h;
  cout << ans << endl;
}


int main()
{
  int _; cin >> _; while (_--)
    work();
  return 0;
}