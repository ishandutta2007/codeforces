#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using VI = vector<int>;
using VVI = vector<VI>;

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  int n; cin >> n;
  set<int> s;
  s.insert(0);
  for (int i = 0; i < n; i++) {
    int a; cin >> a;
    s.insert(a);
  }
  cout << s.size() - 1 << '\n';
  return 0;
}