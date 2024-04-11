#include <cstdio>
#include <algorithm>
using namespace std;

const int M = 998244353;
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

int main(){
  int n, m;
  scanf("%d%d", &n, &m);
  int expected_duration = add(mul(n, inv(m + 1)), 1);
  int expected_rounds = 0;
  for(int i=1; i<=n; i++)
    inc(expected_rounds, inv(i));
  expected_rounds = mul(expected_rounds, m);
  inc(expected_rounds);
  printf("%d\n", mul(expected_duration, expected_rounds));
  return 0;
}