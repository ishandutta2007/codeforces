#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  map<int, int> a;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    int state = 0;
    for (auto c : s) {
      state ^= 1 << c - 'a';
    }
    ++a[state];
  }
  long long answer = 0;
  for (auto p : a) {
    if (p.second) {
      answer += (long long)p.second * (p.second - 1);
      for (int i = 0; i < 26; ++i) {
        answer += (long long)p.second * a[p.first ^ 1 << i];
      }
    }
  }
  printf("%lld\n", answer >> 1);
  return 0;
}