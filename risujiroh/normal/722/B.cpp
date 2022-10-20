#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> p(n);
  for (auto&& e : p) cin >> e;
  cin.ignore();
  const string t = "aeiouy";
  for (int i = 0; i < n; ++i) {
    string s;
    getline(cin, s);
    int cnt = count_if(begin(s), end(s), [&](char c) {
      return t.find(c) != string::npos;
    });
    if (cnt != p[i]) {
      cout << "NO\n";
      exit(0);
    }
  }
  cout << "YES\n";
}