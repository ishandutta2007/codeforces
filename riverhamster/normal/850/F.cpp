#include <cstdio>
#include <algorithm>
#include <cassert>
using namespace std;

const int M = 1000000007;
inline int add(int x, int y) {return x+y>=M ? x+y-M : x+y;}
template<class ...Args> inline int add(int x, int y, Args... args) {return add(add(x, y), args...);}
inline int sub(int x, int y) {return x-y<0 ? x-y+M : x-y;}
inline int mul(int x, int y) {return 1LL * x * y % M;}
template<class ...Args> inline int mul(int x, int y, Args... args) {return mul(mul(x, y), args...);}
inline void inc(int &x, int y=1) {x += y; if(x >= M) x -= M;}
inline void dec(int &x, int y=1) {x -= y; if(x < 0) x += M;}
inline int power(int x, int y){
  int res = 1;
  for(; y; y>>=1, x = mul(x, x)) if(y & 1) res = mul(res, x);
  return res;
}
inline int inv(int x){return power(x, M - 2);}

int n, m;
int f[100005], a[2505];

int main() {
  int n, mx = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
    m += a[i];
    mx = max(mx, a[i]);
  }
  for (int i = 0; i < mx; ++i)
    f[i + 1] = add(f[i], inv(m - i));
  long long res = 0;
  for (int i = 1; i <= n; ++i)
    res += mul(f[a[i]], m - a[i]);
  printf("%d\n", mul(res % M, m - 1));
  return 0;
}