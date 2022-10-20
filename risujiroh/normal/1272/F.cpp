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
  cerr << ' ' << to_string(head), debug(tail...);
}
#ifdef LOCAL
#define DEBUG(...) cerr << "[" << #__VA_ARGS__ << "]:", debug(__VA_ARGS__)
#else
#define DEBUG(...)
#endif

constexpr int inf = 0x3f3f3f3f;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  string s, t;
  cin >> s >> t;
  int n = s.size(), m = t.size();
  int lim = n + m;
  vector< vector< vector<int> > > dp(n + 1, vector< vector<int> >(m + 1, vector<int>(lim + 1, inf)));
  for (int h = 0; h <= lim; ++h) {
    dp[0][0][h] = h;
  }
  auto chmin = [](auto&& l, auto r) {
    if (r < l) {
      l = r;
      return true;
    }
    return false;
  };
  struct Ijh {
    int i, j, h;
    char s;
  };
  vector< vector< vector<Ijh> > > prv(n + 1, vector< vector<Ijh> >(m + 1, vector<Ijh>(lim + 1)));
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= m; ++j) {
      for (int h = 0; h <= lim; ++h) {
        // for (int k = 0; k <= lim; ++k) {
        //   if (s[i] == '(') {
        //     chmin(dp[i + 1][j][k], dp[i][j][h] + 1 + abs(k - (h + 1)));
        //   }
        //   if (s[i] == ')') {
        //     chmin(dp[i + 1][j][k], dp[i][j][h] + 1 + abs(k - (h - 1)));
        //   }
        //   if (t[j] == '(') {
        //     chmin(dp[i][j + 1][k], dp[i][j][h] + 1 + abs(k - (h + 1)));
        //   }
        //   if (t[j] == ')') {
        //     chmin(dp[i][j + 1][k], dp[i][j][h] + 1 + abs(k - (h - 1)));
        //   }
        // }
        if (i < n) {
          if (chmin(dp[i + 1][j][h], dp[i][j][h] + 2)) {
            prv[i + 1][j][h] = {i, j, h, 3};
          }
          if (s[i] == '(') {
            if (h < lim) {
              if (chmin(dp[i + 1][j][h + 1], dp[i][j][h] + 1)) {
                prv[i + 1][j][h + 1] = {i, j, h, 1};
              }
            }
          } else {
            if (h) {
              if (chmin(dp[i + 1][j][h - 1], dp[i][j][h] + 1)) {
                prv[i + 1][j][h - 1] = {i, j, h, 2};
              }
            }
          }
        }
        if (j < m) {
          if (chmin(dp[i][j + 1][h], dp[i][j][h] + 2)) {
            prv[i][j + 1][h] = {i, j, h, 3};
          }
          if (t[j] == '(') {
            if (h < lim) {
              if (chmin(dp[i][j + 1][h + 1], dp[i][j][h] + 1)) {
                prv[i][j + 1][h + 1] = {i, j, h, 1};
              }
            }
          } else {
            if (h) {
              if (chmin(dp[i][j + 1][h - 1], dp[i][j][h] + 1)) {
                prv[i][j + 1][h - 1] = {i, j, h, 2};
              }
            }
          }
        }
        if (i < n and j < m and s[i] == t[j]) {
          if (chmin(dp[i + 1][j + 1][h], dp[i][j][h] + 2)) {
            prv[i + 1][j + 1][h] = {i, j, h, 3};
          }
          if (s[i] == '(') {
            if (h < lim) {
              if (chmin(dp[i + 1][j + 1][h + 1], dp[i][j][h] + 1)) {
                prv[i + 1][j + 1][h + 1] = {i, j, h, 1};
              }
            }
          } else {
            if (h) {
              if (chmin(dp[i + 1][j + 1][h - 1], dp[i][j][h] + 1)) {
                prv[i + 1][j + 1][h - 1] = {i, j, h, 2};
              }
            }
          }
        }
      }
    }
  }
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= m; ++j) {
      DEBUG(i, j, dp[i][j]);
    }
  }
  int i = n, j = m, h = 0;
  DEBUG(i, j, h, dp[i][j][h]);
  string res;
  while (i or j) {
    auto e = prv[i][j][h];
    res = (e.s == 1 ? "(" : e.s == 2 ? ")" : "()") + res;
    i = e.i, j = e.j, h = e.h;
  }
  DEBUG(h);
  cout << res << '\n';
}