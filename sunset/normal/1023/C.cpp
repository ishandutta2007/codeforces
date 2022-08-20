#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n, k;
  string s;
  cin >> n >> k >> s;
  vector<bool> choose(n, false);
  vector<int> left;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '(') {
      left.push_back(i);
    } else {
      choose[left.back()] = choose[i] = true;
      left.pop_back();
      k -= 2;
      if (!k) {
        break;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    if (choose[i]) {
      putchar(s[i]);
    }
  }
  putchar(10);
  return 0;
}