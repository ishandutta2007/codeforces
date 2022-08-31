#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  deque<int> q;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    q.push_back(x);
  }
  vector<int> a, b;
  for (int i = 0; i < n; ++i) {
    int x = q.front();
    q.pop_front();
    int y = q.front();
    q.pop_front();
    a.push_back(x);
    b.push_back(y);
    q.push_front(max(x, y));
    q.push_back(min(x, y));
  }
  vector<int> c(n);
  for (int i = 0; i < n; ++i) {
    c[i] = q.front();
    q.pop_front();
  }
  while (m--) {
    long long t;
    cin >> t;
    --t;
    if (t < n) {
      cout << a[t] << " " << b[t] << "\n";
    } else {
      t = (t - n) % (n - 1);
      cout << c[0] << " " << c[t + 1] << "\n";
    }
  }
  return 0;
}