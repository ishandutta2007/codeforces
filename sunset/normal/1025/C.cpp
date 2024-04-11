#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  string s;
  cin >> s;
  int n = s.length(), last = 0, answer = 0;
  for (int i = 1; i < n; ++i) {
    if (s[i] == s[i - 1]) {
      answer = max(answer, i - last);
      last = i;
    }
  }
  answer = max(answer, n - last);
  if (last) {
    s = s + s;
    n <<= 1;
    last = 0;
    for (int i = 1; i < n; ++i) {
      if (s[i] == s[i - 1]) {
        answer = max(answer, i - last);
        last = i;
      }
    }
    answer = max(answer, n - last);
  }
  printf("%d\n", answer);
  return 0;
}