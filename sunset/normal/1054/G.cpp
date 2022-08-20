#include <bits/stdc++.h>

using namespace std;

const int N = 2000;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    int need = -m;
    vector<bitset<N>> b(n);
    for (int i = 0; i < m; ++i) {
      string s;
      cin >> s;
      for (int j = 0; j < n; ++j) {
        if (s[j] == '1') {
          b[j][i] = true;
          ++need;
        }
      }
    }
    vector<vector<int>> w(n, vector<int> (n));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        w[i][j] = w[j][i] = (b[i] & b[j]).count();
      }
    }
    vector<bool> visit(n);
    vector<int> prev(n, -1), dist(n, -1);
    vector<pair<int, int>> answer;
    int value = 0;
    for (int i = 0; i < n; ++i) {
      int p = -1;
      for (int j = 0; j < n; ++j) {
        if (!visit[j]) {
          if (!~p || dist[j] > dist[p]) {
            p = j;
          }
        }
      }
      if (~prev[p]) {
        answer.emplace_back(p, prev[p]);
        value += w[p][prev[p]];
      }
      visit[p] = true;
      for (int j = 0; j < n; ++j) {
        if (!visit[j] && dist[j] < w[p][j]) {
          dist[j] = w[p][j];
          prev[j] = p;
        }
      }
    }
    if (value == need) {
      cout << "YES" << endl;
      for (auto p : answer) {
        cout << p.first + 1 << " " << p.second + 1 << endl;
      }
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}