#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    long long a, b;
    cin >> a >> b;
    long long c = 0;
    for (long long i = 9; i <= b; i = 10 * i + 9) {
      ++c;
    }
    cout << a * c << '\n';
  }
}