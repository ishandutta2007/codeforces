#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define Debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long LL;
typedef long double LD;
typedef unsigned int uint;
typedef pair <int, int> pii;
typedef unsigned long long uLL;

template <typename T> inline void Read(T &x) {
  char c = getchar();
  bool f = false;
  for (x = 0; !isdigit(c); c = getchar()) {
    if (c == '-') {
      f = true;
    }
  }
  for (; isdigit(c); c = getchar()) {
    x = x * 10 + c - '0';
  }
  if (f) {
    x = -x;
  }
}

template <typename T> inline bool CheckMax(T &a, const T &b) {
  return a < b ? a = b, true : false;
}

template <typename T> inline bool CheckMin(T &a, const T &b) {
  return a > b ? a = b, true : false;
}

const int N = 500005;
const LL inf = 1LL << 60;

priority_queue <pair <LL, int>, vector <pair <LL, int>>, greater <pair <LL, int>>> q;
int n, m, b[N], nxt[N], pre[N];
LL ans, a[N];

int main() {
#ifdef wxh010910
  freopen("d.in", "r", stdin);
#endif
  Read(m), Read(n);
  for (int i = 1; i <= n; ++i) {
    Read(b[i]);
  }
  sort(b + 1, b + n + 1), --n;
  for (int i = 1; i <= n; ++i) {
    a[i] = b[i + 1] - b[i], pre[i] = i - 1, nxt[i] = i + 1;
    q.push(mp(a[i], i));
  }
  nxt[n] = 0;
  for (int i = 1; i <= m; ++i) {
    for (; q.top().X != a[q.top().Y]; q.pop());
    int x = q.top().Y, l = pre[x], r = nxt[x];
    ans += a[x], q.pop();
    pre[nxt[x] = nxt[r]] = x, nxt[pre[x] = pre[l]] = x;
    a[x] = l && r ? min(inf, a[l] + a[r] - a[x]) : inf, a[l] = a[r] = inf;
    q.push(mp(a[x], x));
  }
  printf("%lld\n", ans);
#ifdef wxh010910
  Debug("My Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}