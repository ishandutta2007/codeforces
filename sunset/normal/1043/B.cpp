#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  vector<int> answer;
  for (int i = 1; i <= n; ++i) {
    bool flag = true;
    for (int j = i; j < n; ++j) {
      if (a[j + 1] - a[j] != a[j % i + 1] - a[j % i]) {
        flag = false;
      }
    }
    if (flag) {
      answer.push_back(i);
    }
  }
  cout << answer.size() << endl;
  for (int i = 0; i < answer.size(); ++i) {
    cout << answer[i];
    if (i != answer.size() - 1) {
      cout << " ";
    }
  }
  cout << endl;
  return 0;
}