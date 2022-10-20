#include <iostream>
#include <algorithm>
using namespace std;

char s[505], t[505];

int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k >> s;
    bool op = true;
    auto f = [&](char c) ->char {
      if (c == 'a' || c == 'b' || c == 'a' + k - 1) return 'a';
      return c - 1;
    };
    for (int i = 0; i < n - 1; ++i) {
      char now = op ? f(s[i]) : s[i];
      char nxt = op ? f(s[i + 1]) : s[i + 1];
      if (i + 2 < n && s[i + 2] < min(now, nxt)) {
        t[i] = s[i + 2];
        t[i + 1] = now;
        s[i + 2] = s[i + 1];
        op = false;
        ++i;
        continue;
      }
      else if (nxt < now) {
        t[i] = nxt;
        if (nxt == s[i + 1]) s[i + 1] = now;
        else s[i + 1] = s[i];
        op = false;
      }
      else {
        t[i] = now;
        op = true;
      }
    }
    t[n - 1] = op ? f(s[n - 1]) : s[n - 1];
    t[n] = 0;
    cout << t << '\n';
  }
  return 0;
}