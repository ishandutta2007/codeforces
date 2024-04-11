#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n);
  int mx = 0;
  for (int i = 0; i < n; ++i) {
    int b;
    cin >> b;
    a[i] = mx + b;
    mx = max(mx, a[i]);
  }
  for (int i = 0; i < n; ++i) {
    cout << a[i] << " \n"[i == n - 1];
  }
}