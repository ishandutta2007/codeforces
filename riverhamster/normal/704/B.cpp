#include <cstdio>
#include <queue>
using namespace std;
typedef long long ll;

const int N = 5005;

priority_queue<ll, vector<ll>, greater<ll> > q;
ll a[N], b[N], c[N], d[N], x[N];
ll cost(int i, int j) {
  if (i < j) return a[j] + d[i];
  return b[j] + c[i];
}

int main() {
  int n, s, e;
  scanf("%d%d%d", &n, &s, &e);
  for (int i = 1; i <= n; ++i) scanf("%lld", x + i);
  for (int i = 1; i <= n; ++i) scanf("%lld", a + i), a[i] += x[i];
  for (int i = 1; i <= n; ++i) scanf("%lld", b + i), b[i] -= x[i];
  for (int i = 1; i <= n; ++i) scanf("%lld", c + i), c[i] += x[i];
  for (int i = 1; i <= n; ++i) scanf("%lld", d + i), d[i] -= x[i];
  ll res;
  if (s == 1 || e == 1) res = cost(s, e);
  else res = cost(s, 1) + cost(1, e);
  for (int i = 2; i <= n; ++i) {
    if (i == s) q.push(d[i] - c[i]);
    else if (i == e) q.push(b[i] - a[i]);
    else {
      if (i < s) q.push(b[i] - a[i]);
      if (i < e) q.push(d[i] - c[i]);
      res += a[i] + c[i] + q.top(); q.pop();
      if (i > s) q.push(b[i] - a[i]);
      if (i > e) q.push(d[i] - c[i]);
    }
  }
  printf("%lld\n", res);
  return 0;
}