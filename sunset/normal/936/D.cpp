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

const int N = 3000005;
const int inf = 0x7f7f7f7f;

int n, p, q, t, tot, tim[2];
pair <pii, int> f[N][2];
vector <int> all, mov;
pii eve[N], lst[2];
vector <pii> sot;

int main() {
#ifdef wxh010910
  freopen("d.in", "r", stdin);
#endif
  Read(n), Read(p), Read(q), Read(t);
  for (int i = 0, x; i < p; ++i) {
    Read(x);
    eve[tot++] = mp(x, 0);
    eve[tot++] = mp(x, 2);
    eve[tot++] = mp(x + 1, 2);
  }
  for (int i = 0, x; i < q; ++i) {
    Read(x);
    eve[tot++] = mp(x, 1);
    eve[tot++] = mp(x, 2);
    eve[tot++] = mp(x + 1, 2);
  }
  sort(eve, eve + tot), tot = unique(eve, eve + tot) - eve;
  tim[0] = tim[1] = t, lst[0] = mp(-1, 0), lst[1] = mp(-1, 1);
  for (int i = 0; i < tot; ++i) {
    int x = eve[i].X, y = eve[i].Y;
    if (y == 2) {
      for (int j = 0; j < 2; ++j) {
        if ((i >= 1 && eve[i - 1].X == x && eve[i - 1].Y == !j) || (i >= 2 && eve[i - 2].X == x && eve[i - 2].Y == !j)) {
          continue;
        }
        if (tim[j] != inf && CheckMin(tim[!j], max(tim[j], x))) {
          f[i][!j] = mp(lst[j], -x), lst[!j] = mp(i, !j);
        }
      }
    } else {
      if (tim[y] < x) {
        f[i][y] = mp(lst[y], tim[y]), tim[y] += t, lst[y] = mp(i, y);
      } else {
        tim[y] = inf;
      }
    }
  }
  if (tim[0] == inf && tim[1] == inf) {
    puts("No");
    return 0;
  }
  puts("Yes");
  pii cur = tim[0] == inf ? lst[1] : lst[0];
  for (; ~cur.X; all.pb(f[cur.X][cur.Y].Y), cur = f[cur.X][cur.Y].X);
  if (cur.Y) {
    all.pb(0);
  }
  reverse(all.begin(), all.end());
  int tmp = 0;
  for (auto x : all) {
    if (x <= 0) {
      mov.pb(-x), tmp = !tmp;
    } else {
      sot.pb(mp(x, tmp));
    }
  }
  printf("%d\n", mov.size());
  for (int i = 0; i < mov.size(); ++i) {
    printf("%d%c", mov[i], i == mov.size() - 1 ? '\n' : ' ');
  }
  if (mov.empty()) {
    putchar(10);
  }
  printf("%d\n", sot.size());
  for (auto x : sot) {
    printf("%d %d\n", x.X, x.Y + 1);
  }
#ifdef wxh010910
  Debug("My Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}