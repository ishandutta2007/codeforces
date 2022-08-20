#include <bits/stdc++.h>

using namespace std;

string to_string(string s) {
  return '"' + s + '"';
}

string to_string(const char *s) {
  return to_string((string)s);
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

template<typename A, typename B> string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template<typename A> string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

void debug_out() {
  cerr << endl;
}

template<typename Head, typename... Tail> void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

const int md = 998244353;

inline void add(int &x, int y) {
  x += y;
  if (x >= md) {
    x -= md;
  }
}

inline void sub(int &x, int y) {
  x -= y;
  if (x < 0) {
    x += md;
  }
}

inline int mul(int x, int y) {
  return (long long)x * y % md;
}

inline int power(int x, int y) {
  int result = 1;
  for (; y; y >>= 1, x = mul(x, x)) {
    if (y & 1) {
      result = mul(result, x);
    }
  }
  return result;
}

template<typename T> class fenwick_t {
 public:
  vector<T> fenw;
  int n;

  fenwick_t(int n):n(n) {
    fenw.resize(n);
  }

  void modify(int x, T value) {
    while (x < n) {
      fenw[x] += value;
      x |= x + 1;
    }
  }

  T query(int x) {
    T result{};
    while (x >= 0) {
      result += fenw[x];
      x = (x & x + 1) - 1;
    }
    return result;
  }

  T get(int l, int r) {
    return query(r) - query(l - 1);
  }
};

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n;
  scanf("%d", &n);
  if (n == 1) {
    puts("0");
    return 0;
  }
  vector<int> w(n + 1);
  w[1] = 0;
  w[2] = 1;
  for (int i = 3; i <= n; ++i) {
    w[i] = mul(i - 1, w[i - 1] + w[i - 2]);
  }
  vector<int> fact(n + 1);
  fact[0] = 1;
  for (int i = 1; i <= n; ++i) {
    fact[i] = mul(fact[i - 1], i);
  }
  vector<vector<int>> f(n + 1, vector<int> (n + 1));
  for (int i = 0; i <= n; ++i) {
    f[i][0] = fact[i];
    for (int j = 1; j <= i; ++j) {
      f[i][j] = f[i][j - 1];
      sub(f[i][j], f[i - 1][j - 1]);
    }
  }
  vector<vector<int>> a(n, vector<int> (n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      scanf("%d", &a[i][j]);
      --a[i][j];
    }
  }
  int answer = 0;
  {
    fenwick_t<int> fenw(n);
    for (int i = 0; i < n; ++i) {
      fenw.modify(i, 1);
    }
    int coef = power(w[n], n - 1);
    for (int i = 0; i < n; ++i) {
      fenw.modify(a[0][i], -1);
      add(answer, mul(fact[n - i - 1], mul(coef, fenw.query(a[0][i] - 1))));
    }
  }
  for (int i = 1; i < n; ++i) {
    fenwick_t<int> foo(n), bar(n);
    vector<int> cnt(n);
    int current = 0;
    auto insert = [&](int x) {
      if (++cnt[x] == 2) {
        ++current;
        foo.modify(x, 1);
      }
    };
    auto get = [&](int x, int y) {
      return y < 0 || y > x ? 0 : f[x][y];
    };
    int coef = power(w[n], n - i - 1);
    for (int j = n - 1; ~j; --j) {
      insert(a[i - 1][j]);
      insert(a[i][j]);
      bar.modify(a[i][j], 1);
      int u = foo.query(a[i][j] - 1), v = bar.query(a[i][j] - 1) - u;
      add(answer, mul(coef, mul(u, get(n - j - 1, current - (cnt[a[i - 1][j]] == 2) - 1))));
      add(answer, mul(coef, mul(v, get(n - j - 1, current - (cnt[a[i - 1][j]] == 2)))));
      if (cnt[a[i - 1][j]] == 2 && a[i - 1][j] < a[i][j]) {
        sub(answer, mul(coef, get(n - j - 1, current - 2)));
      }
    }
  }
printf("%d\n", answer);
  return 0;
}