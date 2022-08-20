#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int d, s;
  cin >> d >> s;
  vector<int> prev(d * (s + 1));
  queue<int> q;
  for (int i = 1; i < 10 && i <= s; ++i) {
    if (!prev[i % d * (s + 1) + i]) {
      prev[i % d * (s + 1) + i] = -1;
      q.push(i % d * (s + 1) + i);
    }
  }
  while (!q.empty()) {
    int a = q.front() / (s + 1), b = q.front() % (s + 1);
    q.pop();
    if (!a && b == s) {
      vector<int> answer;
      while (~prev[a * (s + 1) + b]) {
        int na = prev[a * (s + 1) + b] / (s + 1), nb = prev[a * (s + 1) + b] % (s + 1);
        answer.push_back(b - nb);
        a = na;
        b = nb;
      }
      answer.push_back(b);
      for (int i = answer.size() - 1; ~i; --i) {
        cout << answer[i];
      }
      cout << endl;
      return 0;
    }
    for (int i = 0; i < 10 && b + i <= s; ++i) {
      int na = (a * 10 + i) % d, nb = b + i;
      if (!prev[na * (s + 1) + nb]) {
        prev[na * (s + 1) + nb] = a * (s + 1) + b;
        q.push(na * (s + 1) + nb);
      }
    }
  }
  cout << -1 << endl;
  return 0;
}