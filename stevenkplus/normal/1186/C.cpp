#include <iostream>
using namespace std;

int main() {
  string a, b;
  cin >> a >> b;
  int n = a.size();
  int m = b.size();

  int cnt = 0;
  for(int i = 0; i < m; ++i) {
    if (a[i] != b[i]) ++cnt;
  }

  int inc = 0;
  for(int i = 0; i + 1 < m; ++i) {
    if (b[i] != b[i + 1]) {
      ++inc;
    }
  }

  int ans = 0;
  for(int i = 0; i < n - m + 1; ++i) {
    if (cnt % 2 == 0) ++ans;
    if (a[i] != b[0]) --cnt;
    cnt += inc;
    if (i + m < n) {
      if (a[i + m] != b[m - 1]) {
        ++cnt;
      }
    }
  }
  cout << ans << "\n";
}