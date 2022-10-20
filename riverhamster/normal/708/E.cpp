#include <cstdio>
#include <algorithm>
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

const int N = 1504;
int l[2][N], sl[2][N], dls[2][N], f[2]; // sl : fixed right border, l : all ranges strictly on left, r[i] = l[m - i + 1]
int d[N], ds[N];
int fac[100005], ifac[100005];

int main() {
  int n, m, a, b, t;
  scanf("%d%d%d%d%d", &n, &m, &a, &b, &t);

  int L = max(m, t);
  fac[0] = 1;
  for (int i = 1; i <= L; ++i) fac[i] = mul(fac[i - 1], i);
  ifac[L] = inv(fac[L]);
  for (int i = L - 1; i >= 0; --i) ifac[i] = mul(ifac[i + 1], i + 1);
  int p = mul(a, inv(b)), inp = inv(sub(1, p)), nowp = power(sub(1, p), t);
  if(p == 1) {
    if(t * 2 < m) puts("1");
    else puts("0");
    return 0;
  }
  for (int i = 0, li = min(m, t); i <= li; ++i) {
    d[i] = mul(fac[t], ifac[i], ifac[t - i], nowp);
    nowp = mul(nowp, p, inp);
    ds[i] = add(d[i], i == 0 ? 0 : ds[i - 1]);
  }
  for (int i = min(m, t) + 1; i <= m; ++i)
    ds[i] = add(d[i], ds[i - 1]);

  f[1] = 0;
  for (int i = 1; i <= m; ++i) {
    sl[1][i] = mul(ds[i - 1], d[m - i]);
    inc(f[1], sl[1][i]);
    l[1][i] = add(l[1][i - 1], sl[1][i - 1]);
    dls[1][i] = add(dls[1][i - 1], mul(d[i - 1], l[1][i]));
  }
  for (int i = 2; i <= n; ++i) {
    int now = i & 1, pre = now ^ 1;
    f[now] = 0;
    for (int r = 1; r <= m; ++r) {
      sl[now][r] = mul(d[m - r], sub(mul(sub(f[pre], l[pre][m - r + 1]), ds[r - 1]), dls[pre][r]));
      l[now][r] = add(l[now][r - 1], sl[now][r - 1]);
      dls[now][r] = add(dls[now][r - 1], mul(d[r - 1], l[now][r]));
      inc(f[now], sl[now][r]);
    }
  }
  printf("%d\n", f[n & 1]);
  return 0;
}