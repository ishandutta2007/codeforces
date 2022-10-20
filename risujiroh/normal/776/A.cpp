#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  string s, t;
  cin >> s >> t;
  cout << s << ' ' << t << '\n';
  int n;
  cin >> n;
  set<string> se{s, t};
  while (n--) {
    cin >> s >> t;
    if (se.count(s)) {
      se.erase(s);
    } else {
      se.insert(s);
    }
    if (se.count(t)) {
      se.erase(t);
    } else {
      se.insert(t);
    }
    cout << *begin(se) << ' ' << *next(begin(se)) << '\n';
  }
}