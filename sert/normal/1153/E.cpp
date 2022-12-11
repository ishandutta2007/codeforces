#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#ifdef SERT
  bool D = true;
#else
  bool D = false;
#endif

constexpr int N = 100;

struct pt_t {
  int x{}, y{};
  friend ostream& operator<<(ostream &fo, const pt_t &p) {
      fo << p.x << " " << p.y;
      return fo;
  }
  bool operator==(const pt_t &p) const { return x == p.x && y == p.y; }
  bool operator<(const pt_t &p) const { return x < p.x || (x == p.x && y < p.y); }
  bool operator<=(const pt_t &p) const { return (*this) < p || (*this) == p; }
  pt_t operator+(const pt_t &p) const { return {x + p.x, y + p.y}; }
};

struct rect_t {
  pt_t a{}, b{};
  rect_t() = default;
  rect_t(const pt_t &aa, const pt_t &bb): a(min(aa, bb)), b(max(aa, bb)) {}
  bool contains(const pt_t &p) const { return a.x <= p.x && p.x <= b.x && a.y <= p.y && p.y <= b.y; }
  void fix() { if (b < a) swap(a, b); }
  bool operator==(const rect_t &r) const {
    return (r.a == a && r.b == b) || (r.a == b && r.b == a);
  }
  friend ostream& operator<<(ostream &fo, const rect_t &p) {
    fo << p.a << " " << p.b;
    return fo;
  }
};

mt19937 rnd_gen(3431);
struct test_t {
  pt_t a, b;
  rect_t bound{};
  int n{}, q{};

  test_t() = default;

  explicit test_t(bool near) {
    n = N;
    bound = {{1, 1}, {n, n}};
    q = 0;
    a = {rnd(), rnd()};
    do {
      if (near) {
        int num = 0;
        constexpr array<pt_t, 4> dirs{pt_t{-1, 0}, pt_t{1, 0}, pt_t{0, -1}, pt_t{0, 1}};
        for (const pt_t &dir : dirs) {
          if (bound.contains(a + dir) && rnd(++num) == 1) {
            b = a + dir;
          }
        }
      } else {
        b = {rnd(), rnd()};
      }
    } while (a == b);
    //cout << "gen: " << a << ", " << b << endl;
  }

private:
  int rnd(int mx = -1) {
    if (mx == -1) mx = n;
    return 1 + static_cast<int>(rnd_gen() % mx);
  }
} test;

int ask(const rect_t &rect) {
  if (D) {
    test.q++;
    int ans = static_cast<int>(rect.contains(test.a)) + static_cast<int>(rect.contains(test.b));
    //cout << "? " << rect << " -> " << ans << endl;
    return ans;
  } else {
    int ans;
    cout << "? " << rect << endl;
    cin >> ans;
    return ans;
  }
}

void put(const pt_t &a, const pt_t &b) {
  if (D) {
    if ((a == test.a && b == test.b) || (a == test.b && b == test.a)) {
      cout << "All is ok in " << test.q << " queries" << endl;
    } else {
      cout << "FAIL: " << a << ", " << b << " != " << test.a << ", " << test.b << endl;
      exit(11);
    }
  } else {
    cout << "! " << a << " " << b << endl;
  }
}

void solve(bool near = false) {
  if (D) test = test_t(near);
  int x1 = -1, y1 = -1, x2 = -1, y2 = -1;
  int n = N;
  if (!D) cin >> n;
  for (int i = 1; i <= n; i++) {
    if (ask({{1, 1}, {n, i}}) % 2) {
      y2 = i + 1;
      if (y1 == -1) y1 = i;
    }
    if (ask({{1, 1}, {i, n}}) % 2) {
      x2 = i + 1;
      if (x1 == -1) x1 = i;
    }
  }

  if (min(x1, y1) > 0) {
    if (ask({{1, 1}, {x1, y1}}) % 2 == 0) {
      swap(x1, x2);
    }
  }

  if (x1 == -1) {
    int L = 0, R = n;
    while (R - L > 1) {
      int M = (L + R) / 2;
      if (ask({{1, 1}, {M, y1}}) % 2) R = M;
      else L = M;
    }
    x1 = x2 = R;
  }

  if (y1 == -1) {
    int L = 0, R = n;
    while (R - L > 1) {
      int M = (L + R) / 2;
      if (ask({{1, 1}, {x1, M}}) % 2) R = M;
      else L = M;
    }
    y1 = y2 = R;
  }

  put({x1, y1}, {x2, y2});
}

int main() {
  if (D) {
    for (int i = 0; i < 100; i++) {
      solve(true);
    }
    for (int i = 0; i < 100; i++) {
      solve(false);
    }
  } else {
    solve();
  }
}