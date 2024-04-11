#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using VI = vector<int>;
using VVI = vector<VI>;

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  int n, x, y; cin >> n >> x >> y;
  string s; cin >> s;
  s += "1";
  
  lint k = 0;
  for (int i = 0; i < n; i++) {
    k += s[i] == '0' and s[i + 1] == '1';
  }

  if (x > y or k == 0) {
    cout << k * y << '\n';
  } else {
    cout << (k - 1) * x + y << '\n';
  }
  return 0;
}