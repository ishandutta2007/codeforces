#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int>> p(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i].first;
  }
  for (int i = 0; i < n; ++i) {
    cin >> p[i].second;
  }
  sort(p.begin(), p.end());
  long long ans = 0;
  for (int i = 0; i < n; ) {
    priority_queue<int> q;
    q.push(p[i].second);
    long long sum = p[i].second;
    int cur = p[i].first;
    int j = i + 1;
    while (true) {
      while (j < n && p[j].first <= cur) {
        q.push(p[j].second);
        sum += p[j++].second;
      }
      if ((int) q.size() == 1) {
        break;
      }
      sum -= q.top();
      ans += sum;
      q.pop();
      ++cur;
    }
    i = j;
  }
  cout << ans << "\n";
  return 0;
}