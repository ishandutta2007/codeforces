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

const int N = 200005;
const int mod = 998244353;

int n, m, add[N << 2], mul[N << 2], sum[N << 2];
set <pair <pii, int>> s[N];

inline void Add(int x, int l, int r, int v) {
  add[x] = (add[x] + v) % mod;
  sum[x] = (sum[x] + 1LL * v * (r - l + 1)) % mod;
}

inline void Mul(int x, int v) {
  mul[x] = 1LL * mul[x] * v % mod;
  add[x] = 1LL * add[x] * v % mod;
  sum[x] = 1LL * sum[x] * v % mod;
}

inline void PushUp(int x) {
  sum[x] = (sum[x << 1] + sum[x << 1 | 1]) % mod;
}

inline void PushDown(int x, int l, int r) {
  int mid = l + r >> 1;
  if (mul[x] != 1) {
    Mul(x << 1, mul[x]), Mul(x << 1 | 1, mul[x]), mul[x] = 1;
  }
  if (add[x]) {
    Add(x << 1, l, mid, add[x]), Add(x << 1 | 1, mid + 1, r, add[x]), add[x] = 0;
  }
}

inline void Build(int x, int l, int r) {
  mul[x] = 1;
  if (l == r) {
    return ;
  }
  int mid = l + r >> 1;
  Build(x << 1, l, mid), Build(x << 1 | 1, mid + 1, r);
}

inline void Add(int x, int l, int r, int ql, int qr) {
  if (l == ql && r == qr) {
    Add(x, l, r, 1);
    return ;
  }
  PushDown(x, l, r);
  int mid = l + r >> 1;
  if (qr <= mid) {
    Add(x << 1, l, mid, ql, qr);
  } else if (ql > mid) {
    Add(x << 1 | 1, mid + 1, r, ql, qr);
  } else {
    Add(x << 1, l, mid, ql, mid), Add(x << 1 | 1, mid + 1, r, mid + 1, qr);
  }
  PushUp(x);
}

inline void Mul(int x, int l, int r, int ql, int qr) {
  if (l == ql && r == qr) {
    Mul(x, 2);
    return ;
  }
  PushDown(x, l, r);
  int mid = l + r >> 1;
  if (qr <= mid) {
    Mul(x << 1, l, mid, ql, qr);
  } else if (ql > mid) {
    Mul(x << 1 | 1, mid + 1, r, ql, qr);
  } else {
    Mul(x << 1, l, mid, ql, mid), Mul(x << 1 | 1, mid + 1, r, mid + 1, qr);
  }
  PushUp(x);
}

inline int Query(int x, int l, int r, int ql, int qr) {
  if (l == ql && r == qr) {
    return sum[x];
  }
  PushDown(x, l, r);
  int mid = l + r >> 1;
  if (qr <= mid) {
    return Query(x << 1, l, mid, ql, qr);
  } else if (ql > mid) {
    return Query(x << 1 | 1, mid + 1, r, ql, qr);
  } else {
    return (Query(x << 1, l, mid, ql, mid) + Query(x << 1 | 1, mid + 1, r, mid + 1, qr)) % mod;
  }
}

inline void Insert(set <pair <pii, int>> &s, int l, int r) {
  auto i = --s.lower_bound(mp(mp(l + 1, l + 1), 0)), j = --s.lower_bound(mp(mp(r + 1, r + 1), 0));
  if (i == j) {
    int L = i->X.X, R = i->X.Y, z = i->Y;
    if (i->Y) {
      Mul(1, 1, n, l, r);
    } else {
      Add(1, 1, n, l, r);
    }
    s.erase(i);
    s.insert(mp(mp(l, r), 1));
    if (l != L) {
      s.insert(mp(mp(L, l - 1), z));
    }
    if (r != R) {
      s.insert(mp(mp(r + 1, R), z));
    }
  } else {
    if (i->Y) {
      Mul(1, 1, n, l, i->X.Y);
    } else {
      Add(1, 1, n, l, i->X.Y);
    }
    if (j->Y) {
      Mul(1, 1, n, j->X.X, r);
    } else {
      Add(1, 1, n, j->X.X, r);
    }
    auto k = i;
    for (++k; k != j; ++k) {
      if (k->Y) {
        Mul(1, 1, n, k->X.X, k->X.Y);
      } else {
        Add(1, 1, n, k->X.X, k->X.Y);
      }
    }
    for (k = i, ++k; k != j; s.erase(k++));
    int L = i->X.X, R = j->X.Y;
    s.insert(mp(mp(l, r), 1));
    if (l != L) {
      s.insert(mp(mp(L, l - 1), i->Y));
    }
    if (r != R) {
      s.insert(mp(mp(r + 1, R), j->Y));
    }
    s.erase(i), s.erase(j);
  }
}

int main() {
#ifdef wxh010910
  freopen("d.in", "r", stdin);
#endif
  Read(n), Read(m), Build(1, 1, n);
  for (int i = 1; i <= n; ++i) {
    s[i].insert(mp(mp(1, n), false));
  }
  for (int i = 1, o, l, r; i <= m; ++i) {
    Read(o), Read(l), Read(r);
    if (o == 1) {
      int x;
      Read(x), Insert(s[x], l, r);
    } else {
      printf("%d\n", Query(1, 1, n, l, r));
    }
  }
#ifdef wxh010910
  Debug("My Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}