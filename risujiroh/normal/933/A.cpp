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

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto&& e : a) {
    cin >> e;
    --e;
  }
  vector<vector<int>> cum(2, vector<int>(n + 1));
  for (int x = 0; x < 2; ++x) {
    for (int i = n; i--; ) {
      cum[x][i] = (a[i] == x) + cum[x][i + 1];
    }
  }
  vector<vector<vector<int>>> dp(2, vector<vector<int>>(n + 1, vector<int>(n + 1)));
  for (int r = 1; r <= n; ++r) {
    for (int l = r; l--; ) {
      dp[0][l][r] = a[l] ? dp[0][l + 1][r] : 1 + dp[0][l + 1][r];
      dp[1][l][r] = a[l] ? 1 + max(dp[0][l + 1][r], dp[1][l + 1][r]) : dp[1][l + 1][r];
      assert(dp[0][l][r] == cum[0][l] - cum[0][r]);
    }
  }
  DEBUG(dp[1]);
  int res = 0;
  for (int r = 0; r <= n; ++r) {
    for (int l = 0; l <= r; ++l) {
      res = max(res, (cum[0][0] - cum[0][l]) + max(dp[0][l][r], dp[1][l][r]) + (cum[1][r] - cum[1][n]));
    }
  }
  cout << res << '\n';
}