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
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto&& e : a) {
    cin >> e;
  }
  vector<int> t(n);
  for (auto&& e : t) {
    cin >> e;
  }
  map<int, vector<int>> mp;
  for (int i = 0; i < n; ++i) {
    mp[a[i]].push_back(i);
  }
  priority_queue<pair<int, int>> pq;
  long long sum = 0;
  auto add = [&](int i) {
    pq.emplace(t[i], i);
    sum += t[i];
  };
  auto pop = [&]() {
    sum -= pq.top().first;
    pq.pop();
  };
  long long res = 0;
  auto it = begin(mp);
  while (it != end(mp)) {
    DEBUG(*it);
    while (not it->second.empty()) {
      add(it->second.back());
      it->second.pop_back();
    }
    pop();
    if (not pq.empty()) {
      mp[it->first + 1];
      res += sum;
    }
    ++it;
  }
  cout << res << '\n';
}