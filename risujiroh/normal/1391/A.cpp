#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> p(n);
    int cur = n;
    for (int i = 0; i < n; i += 2) {
      p[i] = cur--;
    }
    for (int i = 1; i < n; i += 2) {
      p[i] = cur--;
    } 
    for (int i = 0; i < n; ++i) {
      cout << p[i] << " \n"[i == n - 1];
    }
  }
}