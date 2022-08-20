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

map <LL, vector <pair <LL, int>>> q;
LL cur, dis[N], pri[N];
bool ans[N], vis[N];
int cnt;

inline int Rand() {
  return rand() << 15 | rand();
}

inline LL RandLL() {
  return (LL)Rand() << 30 | Rand();
}

inline LL Qul(LL x, LL y, LL mod) {
  return ((x * y - (LL)(((LD)x * y + 0.5) / mod) * mod) % mod + mod) % mod;
}

inline LL Qow(LL x, LL y, LL mod) {
  LL r = 1;
  for (; y; y >>= 1, x = Qul(x, x, mod)) {
    if (y & 1) {
      r = Qul(r, x, mod);
    }
  }
  return r;
}

inline bool MillerRabin(LL n) {
  if (n == 2) {
    return true;
  }
  if (n < 2 || !(n & 1)) {
    return false;
  }
  LL a, x, y, u = n - 1;
  int t = 0;
  for (; !(u & 1); u >>= 1, ++t);
  for (int i = 0; i < 10; ++i) {
    a = RandLL() % (n - 1) + 1, x = Qow(a, u, n);
    for (int j = 0; j < t; ++j, x = y) {
      if ((y = Qul(x, x, n)) == 1 && x != 1 && x != n - 1) {
        return false;
      }
    }
    if (x != 1) {
      return false;
    }
  }
  return true;
}

inline LL PollardRho(LL a, LL c) {
  LL k = 2, x = RandLL() % a, y = x, p = 1;
  for (LL i = 1; p == 1; ++i) {
    x = (Qul(x, x, a) + c) % a, p = __gcd(abs(x - y), a);
    if (i == k) {
      y = x, k <<= 1;
    }
  }
  return p;
}

inline void Divide(LL x) {
  if (x == 1) {
    return ;
  }
  if (MillerRabin(x)) {
    pri[cnt++] = x;
    return ;
  }
  LL p = x;
  while (p >= x) {
    p = PollardRho(x, RandLL() % (x - 1));
  }
  Divide(p), Divide(x / p);
}

inline void GCD(LL a, LL b, LL &x, LL &y) {
  if (!b) {
    x = 1, y = 0;
  } else {
    GCD(b, a % b, y, x), y -= a / b * x;
  }
}

int main() {
#ifdef wxh010910
  freopen("d.in", "r", stdin);
#endif
  int T;
  Read(T);
  for (int i = 1; i <= T; ++i) {
    LL n, k;
    Read(n), Read(k);
    q[k].pb(mp(n, i));
  }
  for (auto i : q) {
    cur = i.X;
    if (cur == 1) {
      continue;
    }
    cnt = 0, Divide(cur);
    sort(pri, pri + cnt);
    cnt = unique(pri, pri + cnt) - pri;
    if (cnt == 1) {
      for (auto e : i.Y) {
        if (e.X % cur == 0) {
          ans[e.Y] = true;
        }
      }
    } else if (cnt == 2) {
      LL x, y;
      GCD(pri[0], pri[1], x, y);
      for (auto e : i.Y) {
        LL z = e.X, u = Qul(x, z, pri[1]), v = Qul(y, z, pri[0]);
        if (z / pri[0] >= u && z / pri[1] >= v && u * pri[0] + v * pri[1] <= z) {
          ans[e.Y] = true;
        }
      }
    } else {
      priority_queue <pair <LL, int>> q;
      for (int i = 0; i < pri[0]; ++i) {
        dis[i] = 1LL << 60, vis[i] = false;
      }
      dis[0] = 0, q.push(mp(0, 0));
      while (!q.empty()) {
        int x = q.top().Y;
        q.pop();
        if (vis[x]) {
          continue;
        }
        vis[x] = true;
        for (int i = 1; i < cnt; ++i) {
          if (CheckMin(dis[(x + pri[i]) % pri[0]], dis[x] + pri[i])) {
            q.push(mp(-(dis[x] + pri[i]), (x + pri[i]) % pri[0]));
          }
        }
      }
      for (auto e : i.Y) {
        if (dis[e.X % pri[0]] <= e.X) {
          ans[e.Y] = true;
        }
      }
    }
  }
  for (int i = 1; i <= T; ++i) {
    if (ans[i]) {
      puts("YES");
    } else {
      puts("NO");
    }
  }
#ifdef wxh010910
  Debug("My Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}