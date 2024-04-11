#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  string s;
  cin >> s;
  int n = s.length();
  vector<int> answer(n);
  for (int i = 0; i < n - 1; ++i) {
    if (s[i] != s[i + 1]) {
      reverse(s.begin(), s.begin() + i + 1);
      answer[i] = 1;
    }
  }
  if (s[0] == 'b') {
    answer[n - 1] = 1;
  }
  for (int i = 0; i < n; ++i) {
    cout << answer[i];
    if (i != n - 1) {
      cout << " ";
    }
  }
  cout << endl;
  return 0;
}