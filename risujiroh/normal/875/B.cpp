#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  int r = n;
  vector a(n, 0);
  for (int i = 0; i < n; ++i) {
    cout << i + 1 - (n - r) << ' ';
    int p;
    cin >> p;
    --p;
    a[p] = 1;
    while (r and a[r - 1]) {
      --r;
    }
  }
  cout << "1\n";
}