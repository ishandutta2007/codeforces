#include <bits/stdc++.h>

using namespace std;

const int md = 1e9 + 7;

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

  T query(int l, int r) {
    return query(r) - query(l - 1);
  }
};

template<typename T> class fenwick_md_t {
 public:
  vector<T> fenw;
  int n;

  fenwick_md_t(int n):n(n) {
    fenw.resize(n);
  }

  void modify(int x, T value) {
    while (x < n) {
      fenw[x] = (fenw[x] + value) % md;
      x |= x + 1;
    }
  }

  T query(int x) {
    T result{};
    while (x >= 0) {
      result = (result + fenw[x]) % md;
      x = (x & x + 1) - 1;
    }
    return result;
  }

  T query(int l, int r) {
    return (query(r) - query(l - 1) + md) % md;
  }
};

int add(int x, int y) {
  x += y;
  if (x >= md) {
    x -= md;
  }
  return x;
}

int sub(int x, int y) {
  x -= y;
  if (x < 0) {
    x += md;
  }
  return x;
}

int mul(int x, int y) {
  return (long long)x * y % md;
}

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n, q;
  scanf("%d %d", &n, &q);
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    a[i] -= i;
  }
  vector<int> w(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &w[i]);
  }
  fenwick_t<long long> fenwick(n);
  fenwick_md_t<int> weight(n);
  for (int i = 0; i < n; ++i) {
    fenwick.modify(i, w[i]);
    weight.modify(i, (long long)w[i] * a[i] % md);
  }
  while (q--) {
    int x, y;
    scanf("%d %d", &x, &y);
    if (x < 0) {
      x = -(x + 1);
      fenwick.modify(x, -w[x]);
      weight.modify(x, md - (long long)w[x] * a[x] % md);
      w[x] = y;
      fenwick.modify(x, w[x]);
      weight.modify(x, (long long)w[x] * a[x] % md);
    } else {
      int l = x - 1, r = y - 1;
      long long sum = fenwick.query(l, r);
      int low = l, high = r - 1, result = r;
      while (low <= high) {
        int mid = low + high >> 1;
        if (fenwick.query(l, mid) >= sum + 1 >> 1) {
          result = mid;
          high = mid - 1;
        } else {
          low = mid + 1;
        }
      }
      int answer = 0;
      answer = add(answer, sub(mul(fenwick.query(l, result) % md, a[result]), weight.query(l, result)));
      answer = add(answer, sub(weight.query(result, r), mul(fenwick.query(result, r) % md, a[result])));
      printf("%d\n", answer);
    }
  }
  return 0;
}