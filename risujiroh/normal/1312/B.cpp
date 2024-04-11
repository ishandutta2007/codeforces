#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto&& e : a) {
      cin >> e;
    }
    sort(rbegin(a), rend(a));
    for (int i = 0; i < n; ++i) {
      cout << a[i] << " \n"[i == n - 1];
    }
  }
}