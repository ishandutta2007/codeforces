#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> p(n << 1);
  for (int i = 0; i < n << 1; ++i) {
    cin >> p[i];
  }
  vector<int> a(m), b(m);
  for (int i = 0; i < m; ++i) {
    cin >> a[i] >> b[i];
    --a[i];
    --b[i];
    if (p[a[i]] < p[b[i]]) {
      swap(a[i], b[i]);
    }
  }
  int t;
  cin >> t;
  --t;
  vector<bool> visit(n << 1);
  int prev = -1;
  for (int i = 0; i < n << 1; ++i) {
    if ((i & 1) == t) {
      int must = -1;
      for (int j = 0; j < m; ++j) {
        if ((!visit[a[j]] || !visit[b[j]]) && (a[j] == prev || b[j] == prev)) {
          must = a[j] + b[j] - prev;
        }
      }
      if (~must) {
        cout << must + 1 << endl;
        visit[must] = true;
        continue;
      }
      int pairs = -1;
      for (int j = 0; j < m; ++j) {
        if (!visit[a[j]] && !visit[b[j]]) {
          pairs = a[j];
        }
      }
      if (~pairs) {
        cout << pairs + 1 << endl;
        visit[pairs] = true;
        continue;
      }
      int choose = -1;
      for (int j = 0; j < n << 1; ++j) {
        if (!visit[j] && (!~choose || p[j] > p[choose])) {
          choose = j;
        }
      }
      cout << choose + 1 << endl;
      visit[choose] = true;
    } else {
      cin >> prev;
      --prev;
      visit[prev] = true;
    }
  }
  return 0;
}