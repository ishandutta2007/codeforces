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

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  const string one = "one", two = "two";
  auto chmax = [](auto&& l, auto r) {
    if (r > l) {
      l = r;
      return true;
    }
    return false;
  };
  while (t--) {
    string s;
    cin >> s;
    int n = s.size();
    vector< array< array<int, 3>, 3 > > dp(n + 1);
    vector< array< array<pair<int, int>, 3>, 3 > > prv(n + 1);
    for (auto&& v : dp[0]) {
      fill(begin(v), end(v), -1e9);
    }
    dp[0][0][0] = 0;
    for (int i = 0; i < n; ++i) {
      // dp[i + 1] = dp[i];
      for (int x = 0; x < 3; ++x) {
        for (int y = 0; y < 3; ++y) {
          if (chmax(dp[i + 1][x][y], dp[i][x][y])) {
            prv[i + 1][x][y] = {x, y};
          }
        }
      }
      for (int x = 0; x < 3; ++x) {
        for (int y = 0; y < 3; ++y) {
          if (x == 2 and s[i] == one[x]) {
            continue;
          }
          if (y == 2 and s[i] == two[y]) {
            continue;
          }
          int nx = -1, ny = -1;
          if (x == 1 and s[i] == one[x]) {
            nx = 2;
          } else if (s[i] == one[0]) {
            nx = 1;
          } else {
            nx = 0;
          }
          if (y == 1 and s[i] == two[y]) {
            ny = 2;
          } else if (s[i] == two[0]) {
            ny = 1;
          } else {
            ny = 0;
          }
          if (chmax(dp[i + 1][nx][ny], dp[i][x][y] + 1)) {
            prv[i + 1][nx][ny] = {x, y};
          }
        }
      }
    }
    int mx = -1;
    int nx = -1, ny = -1;
    for (int x = 0; x < 3; ++x) {
      for (int y = 0; y < 3; ++y) {
        if (dp[n][x][y] > mx) {
          mx = dp[n][x][y];
          nx = x, ny = y;
        }
      }
    }
    vector<int> res;
    for (int i = n; i--; ) {
      int px, py;
      tie(px, py) = prv[i + 1][nx][ny];
      if (dp[i][px][py] == dp[i + 1][nx][ny]) {
        res.push_back(i);
      }
      nx = px, ny = py;
      DEBUG(i, nx, ny, dp[i][nx][ny]);
    }
    reverse(begin(res), end(res));
    int m = res.size();
    cout << m << '\n';
    for (int i = 0; i < m; ++i) {
      cout << res[i] + 1 << " \n"[i == m - 1];
    }
  }
}