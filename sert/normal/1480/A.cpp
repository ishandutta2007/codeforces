#include <bits/stdc++.h>
using namespace std;

void solve() {
  string s;
  cin >> s;
  bool kek = false;
  for (char &ch : s) {
    kek = !kek;
    if (kek) ch = (ch == 'a' ? 'b' : 'a');
    else ch = (ch == 'z' ? 'y' : 'z');
  }
  cout << s << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t; cin >> t;
  while (t--) solve();
}