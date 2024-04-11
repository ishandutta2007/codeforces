#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, na, nb;
    cin >> n >> na >> nb;
    vector<int> a(na);
    for (auto&& e : a) {
      cin >> e;
    }
    vector<int> b(nb);
    for (auto&& e : b) {
      cin >> e;
    }
    if (*max_element(begin(a), end(a)) == n) {
      cout << "YES" << '\n';
    } else {
      cout << "NO" << '\n';
    }
  }
}