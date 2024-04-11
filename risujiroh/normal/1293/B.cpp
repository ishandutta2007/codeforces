#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  double res = 0;
  for (int i = n; i--; ) {
    res += 1.0 / (i + 1);
  }
  cout << fixed << setprecision(20) << res << '\n';
}