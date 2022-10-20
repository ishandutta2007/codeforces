#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    vector<long long> a(3);
    for (auto&& e : a) {
      cin >> e;
    }
    sort(begin(a), end(a));
    if (a[2] <= a[0] + a[1] + 1) {
      cout << "Yes" << '\n';
    } else {
      cout << "No" << '\n';
    }
  }
}