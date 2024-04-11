#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int n = s.size();
  int j = n - 1;
  vector<int> ans;
  for (int i = 0; i < n; ++i) {
    if (s[i] == ')') continue;
    while (j > i && s[j] == '(') {
      --j;
    }
    if (j > i) {
      ans.push_back(i + 1);
      ans.push_back(j + 1);
      --j;
    } else {
      break;
    }
  }
  if (ans.size() == 0) {
    cout << "0\n";
    return 0;
  }
  sort(ans.begin(), ans.end());
  cout << "1\n";
  cout << ans.size() << "\n";
  for (int i: ans) {
    cout << i << " ";
  }
  cout << "\n";
}