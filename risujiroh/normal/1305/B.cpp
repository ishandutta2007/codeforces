#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  string s;
  cin >> s;
  int n = s.size();
  int l = 0, r = n - 1;
  vector<int> res;
  while (true) {
    while (l < r and s[l] != '(') {
      ++l;
    }
    while (l < r and s[r] != ')') {
      --r;
    }
    if (s[l] == '(' and s[r] == ')') {
      res.push_back(l);
      res.push_back(r);
      ++l, --r;
    } else {
      break;
    }
  }
  sort(begin(res), end(res));
  if (res.empty()) {
    cout << "0\n";
  } else {
    cout << "1\n";
    cout << res.size() << '\n';
    for (int i = 0; i < (int)res.size(); ++i) {
      cout << res[i] + 1 << " \n"[i == (int)res.size() - 1];
    }
  }
}