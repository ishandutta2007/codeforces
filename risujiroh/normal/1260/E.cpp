#include <bits/stdc++.h>
using namespace std;

string to_string(string s) { return '"' + s + '"'; }
string to_string(bool b) { return b ? "true" : "false"; }
template<class T, class U> string to_string(pair<T, U> p);
template<class C> string to_string(C c) {
  string res = "{";
  for (auto e : c) res += to_string(e) + ", ";
  return res += "}";
}
template<size_t N> string to_string(bitset<N> bs) {
  string res;
  for (size_t i = 0; i < N; ++i) res += '0' + bs[i];
  return res;
}
template<class T, class U> string to_string(pair<T, U> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

void debug() { cerr << '\n'; }
template<class Head, class... Tail> void debug(Head head, Tail... tail) {
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
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto&& e : a) {
    cin >> e;
  }
  int k = find(begin(a), end(a), -1) - begin(a);
  k = n - 1 - k;
  int sum = 0, nxt = n / 2;
  long long res = 0;
  while (sum < k) {
    int i = min_element(end(a) - sum - 1, end(a)) - begin(a);
    res += a[i];
    a[i] = 2e9;
    sum += nxt;
    nxt /= 2;
  }
  cout << res << '\n';
}