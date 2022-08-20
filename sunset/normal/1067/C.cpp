#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  vector<pair<int, int>> answer;
  answer.emplace_back(0, 0);
  for (int i = 1; answer.size() < n; ++i) {
    answer.emplace_back(i, 0);
    answer.emplace_back(0, i);
    answer.emplace_back(-i, 0);
    answer.emplace_back(0, -i);
  }
  for (int i = 0; i < n; ++i) {
    cout << answer[i].first << " " << answer[i].second << endl;
  }
  return 0;
}