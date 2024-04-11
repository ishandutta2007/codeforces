#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n, m, q;
  cin >> n >> m >> q;
  vector<int> power(n + 1);
  power[0] = 1;
  for (int i = 0; i < n; ++i) {
    power[i + 1] = power[i] * 3;
  }
  vector<int> a(1 << n);
  while (m--) {
    int x;
    cin >> x;
    ++a[x];
  }
  vector<int> value(1 << n);
  for (int i = 0; i < 1 << n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i >> j & 1) {
        value[i] += power[j];
      }
    }
  }
  vector<int> result(power[n]);
  for (int i = 0; i < 1 << n; ++i) {
    for (int j = 0; j < 1 << n; ++j) {
      result[value[i] + value[j]] += a[i] * a[j];
    }
  }
  while (q--) {
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    int base = 0;
    vector<int> choose;
    for (int i = 0; i < n; ++i) {
      if (s[i] == 'A') {
        choose.push_back(power[i]);
      } else if (s[i] == 'X') {
        choose.push_back(power[i] << 1);
      } else if (s[i] == 'a') {
        base += power[i] << 1;
      } else if (s[i] == 'o') {
        base += power[i];
        choose.push_back(power[i]);
      } else if (s[i] == 'x') {
        base += power[i];
      }
    }
    int answer = 0;

    function<void(int, int)> dfs = [&](int x, int value) {
      if (x == choose.size()) {
        answer += result[value];
      } else {
        dfs(x + 1, value);
        dfs(x + 1, value + choose[x]);
      }
    };

    dfs(0, base);
    cout << answer << endl;
  }
  return 0;
}