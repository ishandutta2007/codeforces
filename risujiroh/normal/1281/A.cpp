#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    int n = s.size();
    if (s.substr(n - 2) == "po") {
      cout << "FILIPINO\n";
    } else if (s.substr(n - 4) == "desu" or s.substr(n - 4) == "masu") {
      cout << "JAPANESE\n";
    } else {
      assert(s.substr(n - 5) == "mnida");
      cout << "KOREAN\n";
    }
  }
}