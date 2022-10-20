#include <bits/stdc++.h>
using namespace std;

string to_string(string s) { return '"' + s + '"'; }
string to_string(bool b) { return b ? "true" : "false"; }
template <size_t N> string to_string(bitset<N> bs) {
  string res;
  for (size_t i = 0; i < N; ++i) res += '0' + bs[i];
  return res;
}
string to_string(vector<bool> v) {
  string res = "{";
  for (bool e : v) res += to_string(e) + ", ";
  return res += "}";
}
template <class T, class U> string to_string(pair<T, U> p);
template <class C> string to_string(C c) {
  string res = "{";
  for (auto e : c) res += to_string(e) + ", ";
  return res += "}";
}
template <class T, class U> string to_string(pair<T, U> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
void debug() { cerr << '\n'; }
template <class Head, class... Tail> void debug(Head head, Tail... tail) {
  cerr << '\t' << to_string(head), debug(tail...);
}
#ifdef LOCAL
#define DEBUG(...) cerr << "[" << #__VA_ARGS__ << "]:", debug(__VA_ARGS__)
#else
#define DEBUG(...)
#endif

long long tmod(long long a, long long p) {
  return (a %= p) < 0 ? a + p : a;
}
long long mod_inv(long long a, long long p) {
  a = tmod(a, p);
  long long b = p, x = 1, u = 0;
  while (b) {
    long long q = a / b;
    swap(a -= q * b, b);
    swap(x -= q * u, u);
  }
  return a == 1 ? tmod(x, p) : -1;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  if (m == 1) {
    cout << "1\n0\n";
    exit(0);
  }
  vector<bool> b(m, true);
  while (n--) {
    int a;
    cin >> a;
    b[a] = false;
  }
  vector<vector<int>> g(m), a(m);
  for (int v = 0; v < m; ++v) {
    if (v and m % v == 0) {
      for (int to = 0; to < m; to += v) {
        if (to != v and (to == 0 or m % to == 0)) {
          g[v].push_back(to);
        }
      }
    }
    if (b[v]) {
      a[__gcd(v, m) % m].push_back(v);
    }
  }
  DEBUG(a);
  vector<int> dp(m, -1e9);
  dp[0] = a[0].size();
  for (int v = m; v-- > 1; ) {
    for (int to : g[v]) {
      dp[v] = max(dp[v], (int)a[v].size() + dp[to]);
    }
  }
  vector<int> res;
  for (int v = 1; ; ) {
    DEBUG(v);
    res.insert(end(res), begin(a[v]), end(a[v]));
    int mx = -1e9, mv = -1;
    for (int to : g[v]) {
      if (dp[to] > mx) {
        mx = dp[to];
        mv = to;
      }
    }
    if (mx > 0) {
      v = mv;
    } else {
      break;
    }
  }
  DEBUG(res);
  int k = res.size();
  cout << k << '\n';
  for (int i = k; i-- > 1; ) {
    long long p = res[i - 1], q = res[i], d = __gcd(p, (long long)m);
    p /= d, q /= d;
    res[i] = tmod(q * mod_inv(p, m / d), m);
  }
  for (int i = 0; i < k; ++i) {
    cout << res[i] << " \n"[i == k - 1];
  }
}