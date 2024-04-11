#include <bits/stdc++.h>
using namespace std;
using uint = unsigned int;
using lint = long long int;
using ulint = unsigned long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T, class U> void assign(V<T>& v, int n, const U& a) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }


int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  int n, k; cin >> n >> k;
  priority_queue<int> pque;
  for (int i = 0; i < 30; ++i) {
    if (n & 1 << i) pque.push(1 << i);
  }
  if (pque.size() > k or k > n) return cout << "NO" << '\n', 0;
  cout << "YES" << '\n';
  while (pque.size() < k) {
    int x = pque.top(); pque.pop();
    pque.push(x >> 1);
    pque.push(x >> 1);
  }
  cout << pque.top(); pque.pop();
  while (!pque.empty()) {
    cout << ' ' << pque.top(); pque.pop();
  }
  cout << '\n';
}