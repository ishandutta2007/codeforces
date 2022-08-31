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

const int N = 400005;

int n, cnt_x, cnt_y, x[N], y[N], x_l[N], x_r[N], y_l[N], y_r[N], val_max[N << 2], val_min[N << 2];
bool chk[N], see[N];
vector <pii> eve[N];
set <int> s[N << 2];

inline void PushUp(int x) {
  for (; !s[x].empty() && chk[*s[x].rbegin()]; s[x].erase(*s[x].rbegin()));
  int son_max = max(val_max[x << 1], val_max[x << 1 | 1]), son_min = min(val_min[x << 1], val_min[x << 1 | 1]), cur_max = s[x].empty() ? -1 : *s[x].rbegin();
  if (cur_max > son_max) {
    if (see[cur_max] || cur_max < son_min) {
      val_max[x] = -1;
    } else {
      val_max[x] = cur_max;
    }
  } else {
    val_max[x] = son_max;
  }
  val_min[x] = max(cur_max, son_min);
}

inline void Modify(int x, int l, int r, int ql, int qr, int v) {
  if (l == ql && r == qr) {
    if (v) {
      s[x].insert(v);
    }
    PushUp(x);
    return ;
  }
  int mid = l + r >> 1;
  if (qr <= mid) {
    Modify(x << 1, l, mid, ql, qr, v);
  } else if (ql > mid) {
    Modify(x << 1 | 1, mid + 1, r, ql, qr, v);
  } else {
    Modify(x << 1, l, mid, ql, mid, v), Modify(x << 1 | 1, mid + 1, r, mid + 1, qr, v);
  }
  PushUp(x);
}

int main() {
#ifdef wxh010910
  freopen("d.in", "r", stdin);
#endif
  Read(n);
  for (int i = 1; i <= n; ++i) {
    Read(x_l[i]), Read(y_l[i]);
    Read(x_r[i]), Read(y_r[i]);
    x[++cnt_x] = x_l[i], x[++cnt_x] = x_r[i];
    y[++cnt_y] = y_l[i], y[++cnt_y] = y_r[i];
  }
  sort(x + 1, x + cnt_x + 1), cnt_x = unique(x + 1, x + cnt_x + 1) - x - 1;
  sort(y + 1, y + cnt_y + 1), cnt_y = unique(y + 1, y + cnt_y + 1) - y - 1;
  for (int i = 1; i <= n; ++i) {
    x_l[i] = lower_bound(x + 1, x + cnt_x + 1, x_l[i]) - x;
    x_r[i] = lower_bound(x + 1, x + cnt_x + 1, x_r[i]) - x;
    y_l[i] = lower_bound(y + 1, y + cnt_y + 1, y_l[i]) - y;
    y_r[i] = lower_bound(y + 1, y + cnt_y + 1, y_r[i]) - y;
    eve[x_l[i]].pb(mp(i, 0)), eve[x_r[i]].pb(mp(i, 1));
  }
  memset(val_max, -1, sizeof val_max);
  for (int i = 1; i <= cnt_x; ++i) {
    for (auto e : eve[i]) {
      int p = e.X, o = e.Y;
      if (o) {
        chk[p] = true;
      }
      Modify(1, 1, cnt_y, y_l[p], y_r[p] - 1, o ? 0 : p);
    }
    while (val_max[1] >= val_min[1]) {
      int p = val_max[1];
      see[p] = true;
      Modify(1, 1, cnt_y, y_l[p], y_r[p] - 1, 0);
    }
  }
  int ans = 1;
  for (int i = 1; i <= n; ++i) {
    if (see[i]) {
      ++ans;
    }
  }
  printf("%d\n", ans);
#ifdef wxh010910
  Debug("My Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}