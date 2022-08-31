#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int a, b;
  cin >> a >> b;
  int sum = a + b, answer = 0;
  while ((long long)(answer + 2) * (answer + 1) >> 1 <= sum) {
    ++answer;
  }
  vector<bool> visit(answer + 1);
  for (int i = answer; i; --i) {
    if (a >= i) {
      visit[i] = true;
      a -= i;
    }
  }
  int suma = 0, sumb = 0;
  for (int i = 1; i <= answer; ++i) {
    if (visit[i]) {
      ++suma;
    } else {
      ++sumb;
    }
  }
  cout << suma << endl;
  for (int i = 1; i <= answer; ++i) {
    if (visit[i]) {
      cout << i << " ";
    }
  }
  cout << endl;
  cout << sumb << endl;
  for (int i = 1; i <= answer; ++i) {
    if (!visit[i]) {
      cout << i << " ";
    }
  }
  cout << endl;
  return 0;
}