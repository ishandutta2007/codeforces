#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int M = 1000000007;
typedef long long ll;

struct mat {
  int a[2][2];
  mat() {memset(a, 0, sizeof a);}
  int *operator[](int x) {return a[x];}
  const int *operator[](int x) const {return a[x];}
};
mat operator+(const mat &a, const mat &b) {
  mat c;
  for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 2; ++j)
      c[i][j] = (a[i][j] + b[i][j]) % M;
  return c;
}
mat operator*(const mat &a, const mat &b) {
  mat c;
  for (int k = 0; k < 2; ++k)
    for (int i = 0; i < 2; ++i)
      for (int j = 0; j < 2; ++j)
        (c[i][j] += 1LL * a[i][k] * b[k][j] % M) %= M;
  return c;
}
mat operator*(const mat &a, int la) {
  mat c = a;
  for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 2; ++j)
      c[i][j] = 1LL * c[i][j] * la % M;
  return c;
}

mat T;
ll n;
int k;
int C[41][41];

mat power(mat x, ll y) {
  mat p; p[0][0] = p[1][1] = 1;
  for (; y; y >>= 1, x = x * x) if (y & 1) p = p * x;
  return p;
}
int power(int x, int y) {
  int p = 1;
  for (; y; y >>= 1, x = 1LL * x * x % M) if (y & 1) p = 1LL * p * x % M;
  return p;
}
vector<mat> solve(ll n) {
  if (n == 1) return vector<mat>(k + 1, T);
  ll half = n / 2;
  vector<mat> f(k + 1), g = solve(half);
  mat t = power(T, half);
  for (int m = 0; m <= k; ++m) {
    mat s;
    int phalf = 1;
    for (int j = m; j >= 0; --j) {
      f[m] = f[m] + (g[j] * phalf * C[m][j]);
      phalf = 1LL * phalf * (half % M) % M;
    }
    f[m] = t * f[m] + g[m];
  }
  if (n & 1) {
    mat t = power(T, n);
    for (int i = 0; i <= k; ++i)
      f[i] = f[i] + t * power(n % M, i);
  }
  return f;
}

int main() {
  scanf("%lld%d", &n, &k);
  T[0][0] = T[0][1] = T[1][0] = 1; T[1][1] = 0;
  C[0][0] = 1;
  for (int i = 1; i <= k; ++i) {
    C[i][0] = 1;
    for (int j = 1; j <= i; ++j)
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % M;
  }
  printf("%d\n", solve(n)[k][0][0]);
  return 0;
}