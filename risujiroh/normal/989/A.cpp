#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using VI = vector<int>;
using VVI = vector<VI>;

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  string s; cin >> s;
  int n = s.size();
  bool f = false;
  for (int i = 0; i < n - 2; i++) {
    string t = s.substr(i, 3);
    sort(t.begin(), t.end());
    if (t == "ABC") f = true;
  }
  cout << (f ? "Yes" : "No") << '\n';
  return 0;
}