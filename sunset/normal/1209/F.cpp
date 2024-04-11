#include <bits/stdc++.h>

using namespace std;

template <typename T>
T power(T a, long long b) {
  T r = 1;
  while (b) {
    if (b & 1) {
      r *= a;
    }
    a *= a;
    b >>= 1;
  }
  return r;
}

int inverse(int a, int m) {
  a %= m;
  if (a < 0) {
    a += m;
  }
  int b = m, u = 0, v = 1;
  while (a) {
    int t = b / a;
    b -= a * t;
    swap(a, b);
    u -= v * t;
    swap(u, v);
  }
  if (u < 0) {
    u += m;
  }
  return u;
}

template <int _P>
struct modnum {
  static constexpr int P = _P;

 private:
  int v;

 public:
  modnum() : v(0) {
  }

  modnum(long long _v) {
    v = _v % P;
    if (v < 0) {
      v += P;
    }
  }

  explicit operator int() const {
    return v;
  }

  bool operator==(const modnum& o) const {
    return v == o.v;
  }

  bool operator!=(const modnum& o) const {
    return v != o.v;
  }

  modnum inverse() const {
    return modnum(::inverse(v, P));
  }

  modnum operator-() const {
    return modnum(v ? P - v : 0);
  }
  
  modnum operator+() const {
    return *this;
  }

  modnum& operator++() {
    v++;
    if (v == P) {
      v = 0;
    }
    return *this;
  }
  
  modnum& operator--() {
    if (v == 0) {
      v = P;
    }
    v--;
    return *this;
  }

  modnum operator++(int) {
    modnum r = *this;
    ++*this;
    return r;
  }
  
  modnum operator--(int) {
    modnum r = *this;
    --*this;
    return r;
  }

  modnum& operator+=(const modnum& o) {
    v += o.v;
    if (v >= P) {
      v -= P;
    }
    return *this;
  }

  modnum operator+(const modnum& o) const {
    return modnum(*this) += o;
  }

  modnum& operator-=(const modnum& o) {
    v -= o.v;
    if (v < 0) {
      v += P;
    }
    return *this;
  }

  modnum operator-(const modnum& o) const {
    return modnum(*this) -= o;
  }

  modnum& operator*=(const modnum& o) {
    v = (int) ((long long) v * o.v % P);
    return *this;
  }

  modnum operator*(const modnum& o) const {
    return modnum(*this) *= o;
  }
  
  modnum& operator/=(const modnum& o) {
    return *this *= o.inverse();
  }

  modnum operator/(const modnum& o) const {
    return modnum(*this) /= o;
  }
};

template <int _P>
ostream& operator<<(ostream& out, const modnum<_P>& n) {
  return out << int(n);
}

template <int _P>
istream& operator>>(istream& in, modnum<_P>& n) {
  long long _v;
  in >> _v;
  n = modnum<_P>(_v);
  return in;
}

using num = modnum<1000000007>;

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> d(m);
  for (int i = 0; i < m; ++i) {
    int x = i + 1;
    while (x) {
      d[i].push_back(x % 10);
      x /= 10;
    }
    reverse(d[i].begin(), d[i].end());
  }
  vector<int> from(m), to(m);
  int new_n = n;
  for (int i = 0; i < m; ++i) {
    cin >> from[i] >> to[i];
    --from[i];
    --to[i];
    new_n += 2 * (d[i].size() - 1);
  }
  vector<vector<pair<int, int>>> g(new_n);
  new_n = n;
  auto add = [&](int v, int u, int w) {
    int pre = v;
    for (int i = 0; i < (int) d[w].size(); ++i) {
      int nxt = i + 1 < (int) d[w].size() ? new_n++ : u;
      g[pre].emplace_back(nxt, d[w][i]);
      pre = nxt;
    }
  };
  for (int i = 0; i < m; ++i) {
    add(from[i], to[i], i);
    add(to[i], from[i], i);
  }
  queue<vector<int>> q;
  vector<int> who(new_n, 10);
  vector<num> ans(new_n);
  who[0] = 0;
  ans[0] = 0;
  q.push({0});
  while (!q.empty()) {
    vector<int> cur = q.front();
    vector<int> nxt;
    q.pop();
    num res = ans[cur[0]] * 10;
    for (int v : cur) {
      for (auto p : g[v]) {
        int u = p.first;
        int w = p.second;
        if (who[u] == 10) {
          nxt.push_back(u);
        }
        who[u] = min(who[u], w);
      }
    }
    sort(nxt.begin(), nxt.end(), [&](int v, int u) { return who[v] < who[u]; });
    vector<int> add;
    int last = -1;
    for (int v : nxt) {
      if (who[v] != last) {
        if (!add.empty()) {
          q.push(add);
          add.clear();
        }
        last = who[v];
      }
      add.push_back(v);
      ans[v] = res + who[v];
    }
    if (!add.empty()) {
      q.push(add);
      add.clear();
    }
  }
  for (int i = 1; i < n; ++i) {
    cout << ans[i] << "\n";
  }
  return 0;
}