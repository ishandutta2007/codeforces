#include <bits/stdc++.h>
using namespace std;

bool _main() {
  string s;
  cin >> s;
  int n = s.size();
  int cnt = 0;
  for(int i = 0; i < n; ++i) {
    if (s[i] == 'a') {
      ++cnt;
    }
  }

  int l = n - cnt;
  if (l % 2) return false;
  string left = s.substr(0, n - l / 2);
  string right = s.substr(n - l / 2);
  string noAs = "";
  for (int i = 0; i < left.size(); ++i) {
    if (left[i] == 'a') continue;
    noAs += left[i];
  }
  if (noAs != right) return false;
  cout << left << "\n";
  return true;
}

int main() {
  if (!_main()) {
    printf(":(\n");
  }
}