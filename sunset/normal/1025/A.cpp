#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  string s;
  int n;
  cin >> n >> s;
  if (n == 1) {
    puts("Yes");
    return 0;
  }
  vector<bool> visit(26, false);
  for (int i = 0; i < n; ++i) {
    if (visit[s[i] - 'a']) {
      puts("Yes");
      return 0;
    } else {
      visit[s[i] - 'a'] = true;
    }
  }
  puts("No");
  return 0;
}