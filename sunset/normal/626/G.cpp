#include <bits/stdc++.h>

using namespace std;

template <typename T>
struct heap {
  priority_queue<T> foo, bar;

  void push(T x) {
    foo.push(x);
  }

  void pop(T x) {
    bar.push(x);
  }

  T top() {
    while (!bar.empty() && foo.top() == bar.top()) {
      foo.pop(); bar.pop();
    }
    return foo.top();
  }
};

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, t, q;
  cin >> n >> t >> q;
  vector<double> p(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
  }
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> b(n);
  heap<pair<double, int>> foo, bar;
  foo.push(make_pair(-1e9, -1));
  bar.push(make_pair(-1e9, -1));
  for (int i = 0; i < t; ++i) {
    bar.push(make_pair(0, -1));
  }
  auto insert = [&](int i) {
    double e = p[i] * a[i] / (a[i] + b[i]);
    if (b[i] > 0) {
      bar.push(make_pair(-e / (a[i] + b[i] - 1), i));
    }
    if (b[i] < a[i]) {
      foo.push(make_pair(e / (a[i] + b[i] + 1), i));
    }
  };
  auto erase = [&](int i) {
    double e = p[i] * a[i] / (a[i] + b[i]);
    if (b[i] > 0) {
      bar.pop(make_pair(-e / (a[i] + b[i] - 1), i));
    }
    if (b[i] < a[i]) {
      foo.pop(make_pair(e / (a[i] + b[i] + 1), i));
    }
  };
  for (int i = 0; i < n; ++i) {
    insert(i);
  }
  cout << fixed << setprecision(9);
  double ans = 0;
  while (q--) {
    int type, i;
    cin >> type >> i;
    --i;
    ans -= p[i] * b[i] / (a[i] + b[i]);
    erase(i);
    if (type == 1) {
      ++a[i];
    } else {
      --a[i];
      if (b[i] > a[i]) {
        --b[i];
        bar.push(make_pair(0, -1));
      }
    }
    ans += p[i] * b[i] / (a[i] + b[i]);
    insert(i);
    while (foo.top().first + bar.top().first > 1e-9) {
      ans += foo.top().first + bar.top().first;
      int j = foo.top().second, k = bar.top().second;
      if (k == -1) {
        erase(j);
        ++b[j];
        insert(j);
        bar.pop(make_pair(0, -1));
      } else {
        erase(j); erase(k);
        ++b[j]; --b[k];
        insert(j); insert(k);
      }
    }
    cout << ans << "\n";
  }
  return 0;
}