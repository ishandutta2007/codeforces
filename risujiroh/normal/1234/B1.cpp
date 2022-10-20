#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, k; cin >> n >> k;
  set<int> se;
  deque<int> deq;
  while (n--) {
    int i; cin >> i;
    if (se.count(i)) continue;
    if ((int)se.size() == k) {
      se.erase(deq.back());
      deq.pop_back();
    }
    se.insert(i);
    deq.push_front(i);
  }
  int m = deq.size();
  cout << m << '\n';
  for (int i = 0; i < m; ++i) {
    cout << deq[i] << " \n"[i == m - 1];
  }
}