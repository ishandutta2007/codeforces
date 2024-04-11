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

const int N = 100005;

struct Node {
  LL max_suf, min_p, min_r, tag;
} e[N << 2];

int n, m, ans, top, g[N], w[N], sta[N];
vector <pair <int, LL>> adj[N];
LL cur, pre[N], suf[N];

inline void Add(int x, LL v) {
  e[x].max_suf += v;
  e[x].min_r += v;
  e[x].tag += v;
}

inline void PushDown(int x) {
  if (e[x].tag) {
    Add(x << 1, e[x].tag);
    Add(x << 1 | 1, e[x].tag);
    e[x].tag = 0;
  }
}

inline LL Query(int x, int l, int r, LL v) {
  if (l == r) {
    return v + e[x].min_p;
  }
  int mid = l + r >> 1;
  PushDown(x);
  if (v > e[x << 1].max_suf) {
    return min(e[x << 1].min_p + v, Query(x << 1 | 1, mid + 1, r, v));
  } else {
    return min(Query(x << 1, l, mid, v), e[x].min_r);
  }
}

inline void PushUp(int x, int l, int r) {
  e[x].max_suf = max(e[x << 1].max_suf, e[x << 1 | 1].max_suf);
  e[x].min_p = min(e[x << 1].min_p, e[x << 1 | 1].min_p);
  int mid = l + r >> 1;
  PushDown(x), e[x].min_r = Query(x << 1 | 1, mid + 1, r, e[x << 1].max_suf);
}

inline void Build(int x, int l, int r) {
  if (l == r) {
    e[x].min_p = -suf[l], e[x].max_suf = suf[l];
    return ;
  }
  int mid = l + r >> 1;
  Build(x << 1, l, mid), Build(x << 1 | 1, mid + 1, r);
  PushUp(x, l, r);
}

inline void Modify(int x, int l, int r, int ql, int qr, LL v) {
  if (l == ql && r == qr) {
    return Add(x, v);
  }
  int mid = l + r >> 1;
  PushDown(x);
  if (qr <= mid) {
    Modify(x << 1, l, mid, ql, qr, v);
  } else if (ql > mid) {
    Modify(x << 1 | 1, mid + 1, r, ql, qr, v);
  } else {
    Modify(x << 1, l, mid, ql, mid, v), Modify(x << 1 | 1, mid + 1, r, mid + 1, qr, v);
  }
  PushUp(x, l, r);
}

inline int Query(int x, int l, int r, int ql, int qr, LL v) {
  if (l == ql && r == qr) {
    CheckMax(cur, e[x].max_suf);
    if (l == r) {
      return v + e[x].min_p <= m ? l : 0;
    }
    int mid = l + r >> 1;
    PushDown(x);
    if (Query(x << 1 | 1, mid + 1, r, max(v, e[x << 1].max_suf)) <= m) {
      return Query(x << 1 | 1, mid + 1, r, mid + 1, r, max(v, e[x << 1].max_suf));
    } else {
      return Query(x << 1, l, mid, l, mid, v);
    }
  }
  int mid = l + r >> 1;
  PushDown(x);
  if (qr <= mid) {
    return Query(x << 1, l, mid, ql, qr, v);
  } else if (ql > mid) {
    return Query(x << 1 | 1, mid + 1, r, ql, qr, v);
  } else {
    int L = Query(x << 1, l, mid, ql, mid, v), R = Query(x << 1 | 1, mid + 1, r, mid + 1, qr, max(v, cur));
    return max(L, R);
  }
}

inline LL Find(int x, int l, int r, int p) {
  if (l == r) {
    return e[x].tag;
  }
  int mid = l + r >> 1;
  if (p <= mid) {
    return e[x].tag + Find(x << 1, l, mid, p);
  } else {
    return e[x].tag + Find(x << 1 | 1, mid + 1, r, p);
  }
}

inline int Find(int x) {
  int l = x + 1, r = n, ret = x;
  while (l <= r) {
    int mid = l + r + 1 >> 1;
    if (Find(1, 1, n, mid - 1) <= m) {
      ret = mid, l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  return ret;
}

inline void DFS(int x) {
  if (x <= n) {
    cur = -(1LL << 60), CheckMax(ans, Query(1, 1, n, x, Find(x), cur) - x + 1);
  }
  for (auto e : adj[x]) {
    Modify(1, 1, n, x - 1, n, e.Y);
    DFS(e.X);
    Modify(1, 1, n, x - 1, n, -e.Y);
  }
}

int main() {
#ifdef wxh010910
  freopen("d.in", "r", stdin);
#endif
  Read(n), Read(m);
  for (int i = 1; i < n; ++i) {
    Read(w[i]);
  }
  for (int i = 1; i <= n; ++i) {
    Read(g[i]);
  }
  for (int i = 2; i <= n; ++i) {
    pre[i] = pre[i - 1] + g[i - 1] - w[i - 1];
    suf[i] = suf[i - 1] + g[i] - w[i - 1];
  }
  for (int i = 1; i <= n; ++i) {
    for (; top && pre[sta[top]] > pre[i]; --top) {
      adj[i].pb(mp(sta[top], pre[sta[top]] - pre[i]));
    }
    sta[++top] = i;
  }
  for (; top; --top) {
    adj[n + 1].pb(mp(sta[top], 0));
  }
  Build(1, 1, n), DFS(n + 1);
  printf("%d\n", ans);
#ifdef wxh010910
  Debug("My Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}