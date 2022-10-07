#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m, p;
  cin >> n >> m >> p;
  int a = -1, b = -1;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    if (a == -1 && x % p != 0) {
      a = i;
    }
  }
  for (int i = 0; i < m; ++i) {
    int x;
    cin >> x;
    if (b == -1 && x % p != 0) {
      b = i;
    }
  }
  cout << a + b << "\n";
}