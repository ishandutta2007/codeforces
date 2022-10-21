#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto&& e : a) {
    cin >> e;
  }
  vector<int> l(n + 1), r(n + 1);
  for (int i = 0; i < n; ++i) {
    l[i + 1] = l[i] | a[i];
  }
  for (int i = n; i--; ) {
    r[i] = a[i] | r[i + 1];
  }
  int mx = -1, mi = -1;
  for (int i = 0; i < n; ++i) {
    int cur = a[i] & ~(l[i] | r[i + 1]);
    if (cur > mx) {
      mx = cur;
      mi = i;
    }
  }
  swap(a[0], a[mi]);
  for (int i = 0; i < n; ++i) {
    cout << a[i] << " \n"[i == n - 1];
  }
}