#include <bits/stdc++.h>

using namespace std;

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

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n, t;
  scanf("%d %d", &n, &t);
  vector<int> x(n), y(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", &x[i], &y[i]);
  }
  vector<int> all;
  all.push_back(0);
  all.push_back(t + 1);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      int s = max(abs(x[i] - x[j]), abs(y[i] - y[j])) - 1 >> 1;
      if (s <= t) {
        all.push_back(s);
      }
    }
  }
  sort(all.begin(), all.end());
  all.erase(unique(all.begin(), all.end()), all.end());
  auto get = [&](int t) {
    vector<int> dx, dy;
    for (int i = 0; i < n; ++i) {
      dx.push_back(x[i] - t);
      dx.push_back(x[i] + t + 1);
      dy.push_back(y[i] - t);
      dy.push_back(y[i] + t + 1);
    }
    sort(dx.begin(), dx.end());
    sort(dy.begin(), dy.end());
    dx.erase(unique(dx.begin(), dx.end()), dx.end());
    dy.erase(unique(dy.begin(), dy.end()), dy.end());
    vector<vector<pair<pair<int, int>, int>>> events(dx.size());
    for (int i = 0; i < n; ++i) {
      int xl = lower_bound(dx.begin(), dx.end(), x[i] - t) - dx.begin();
      int xr = lower_bound(dx.begin(), dx.end(), x[i] + t + 1) - dx.begin();
      int yl = lower_bound(dy.begin(), dy.end(), y[i] - t) - dy.begin();
      int yr = lower_bound(dy.begin(), dy.end(), y[i] + t + 1) - dy.begin();
      events[xl].emplace_back(make_pair(yl, yr), 1);
      events[xr].emplace_back(make_pair(yl, yr), -1);
    }
    vector<int> cnt(dy.size());
    int answer = 0;
    for (int i = 0; i < dx.size() - 1; ++i) {
      for (auto p : events[i]) {
        for (int j = p.first.first; j < p.first.second; ++j) {
          cnt[j] += p.second;
        }
      }
      for (int j = 0; j < dy.size() - 1; ++j) {
        if (cnt[j]) {
          add(answer, mul(dx[i + 1] - dx[i], dy[j + 1] - dy[j]));
        }
      }
    }
    return answer % md;
  };
  const int m = 3;
  vector<int> inv_fact(m + 1);
  inv_fact[0] = inv_fact[1] = 1;
  inv_fact[2] = (md + 1) / 2;
  inv_fact[3] = (md + 1) / 6;
  vector<int> f(m + 1), foo(m + 1), bar(m + 1);
  auto lagrange = [&](int n) {
    for (int i = 0, coef = 1; i <= m; ++i) {
      foo[i] = coef;
      coef = mul(coef, n - i);
    }
    for (int i = 0, coef = 1; i <= m; ++i) {
      bar[i] = coef;
      coef = mul(coef, m - n - i + md);
    }
    int result = 0;
    for (int i = 0; i <= m; ++i) {
      add(result, mul(f[i], mul(mul(foo[i], bar[m - i]), mul(inv_fact[i], inv_fact[m - i]))));
    }
    return result;
  };
  auto solve = [&](int l, int r) {
    if (r - l <= 3) {
      int answer = 0;
      for (int i = l; i <= r; ++i) {
        add(answer, get(i));
      }
      return answer;
    } else {
      for (int i = 0; i <= m; ++i) {
        f[i] = get(l + i);
        if (i) {
          add(f[i], f[i - 1]);
        }
      }
      return lagrange(r - l);
    }
  };
  int answer = mul(t + 1, get(t));
  for (int i = 0; i < all.size() - 1; ++i) {
    sub(answer, solve(all[i], all[i + 1] - 1));
  }
  printf("%d\n", answer);
  return 0;
}