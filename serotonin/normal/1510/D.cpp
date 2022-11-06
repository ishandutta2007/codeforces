#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

const int M = 1010;
const int N = 100010;
const ld EPS = 1e-11;
const ld INF = 1e16 + 69;

inline bool eq (ld x, ld y) {
  return fabs(x - y) < EPS;
}

int n, d, a[N];
ld to[M], f[N][10];

int main() {
  for (int i = 1; i < M; ++i) {
    to[i] = logl(i);
  }
  cin >> n >> d;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
  }
  for (int dig = 0; dig < 10; ++dig) {
    f[0][dig] = (dig == 1) ? 0 : -INF;
  }
  for (int i = 1; i <= n; ++i) {
    for (int dig = 0; dig < 10; ++dig) {
      f[i][dig] = -INF;  
    }
    int last = a[i] % 10;
    for (int dig = 0; dig < 10; ++dig) {
      f[i][dig] = max(f[i][dig], f[i - 1][dig]);  
      int cur = last * dig % 10;
      f[i][cur] = max(f[i][cur], f[i - 1][dig] + to[a[i]]);
    }
  }
  // cerr << f[n][d] << '\n';
  if (f[n][d] < -6969) {
    cout << "-1\n";
    return 0;
  }
  vector <int> ans;
  int at = n, last = d;
  while (at) {
    bool found = 0;
    int wat = a[at] % 10;
    for (int dig = 0; dig < 10; ++dig) {
      int cur = wat * dig % 10;
      if (cur == last and eq(f[at][last], f[at - 1][dig] + to[a[at]])) {
        ans.emplace_back(a[at]), --at, last = dig, found = 1;
        break;
      } 
    }
    if (found) continue;
    if (eq(f[at - 1][last], f[at][last])) {
      --at; 
      continue;
    }
  }
  if (ans.empty()) {
    cout << "-1\n";
    return 0;
  }
  cout << ans.size() << '\n';
  for (int x : ans) printf("%d ", x); puts("");
  return 0;
}