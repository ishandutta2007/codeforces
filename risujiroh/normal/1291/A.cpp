#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    string res;
    while (n--) {
      char c;
      cin >> c;
      if (c & 1) {
        res += c;
      }
    }
    if (res.size() < 2) {
      cout << "-1\n";
    } else {
      cout << res.substr(0, 2) << '\n';
    }
  }
}