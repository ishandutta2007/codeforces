#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, l = 0, r = 1e9;
  cin >> n;
  cout << 1 << " " << 0 << endl;
  string type;
  cin >> type;
  for (int i = 1; i < n; ++i) {
    int m = l + r >> 1;
    cout << 1 << " " << m << endl;
    string s;
    cin >> s;
    if (s == type) {
      l = m;
    } else {
      r = m;
    }
  }
  cout << 0 << " " << l << " " << 2 << " " << r << endl;
  return 0;
}