#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> answer(n);
  auto solve = [&](int start) {
    vector<vector<vector<int>>> a(5, vector<vector<int>> (5, vector<int> (5)));
    for (int i = 0; i < 5; ++i) {
      for (int j = 0; j < i; ++j) {
        for (int k = 0; k < j; ++k) {
          cout << "? " << start + i + 1 << " " << start + j + 1 << " " << start + k + 1 << endl;
          cin >> a[i][j][k];
        }
      }
    }
    vector<int> p(5);
    for (int i = 0; i < 5; ++i) {
      p[i] = i;
    }
    do {
      vector<long long> min_add(5), max_add(5);
      for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < i; ++j) {
          for (int k = 0; k < j; ++k) {
            int x = min(p[i], min(p[j], p[k]));
            int y = max(p[i], max(p[j], p[k]));
            if (!x) {
              min_add[y] = a[i][j][k];
            }
            if (y == 4) {
              max_add[x] = a[i][j][k];
            }
          }
        }
      }
      long long sum = min_add[2] + min_add[4] + max_add[2] >> 1;
      vector<long long> value(5);
      value[0] = sum - max_add[2];
      value[2] = sum - min_add[4];
      value[4] = sum - min_add[2];
      value[1] = max_add[1] - value[4];
      value[3] = min_add[3] - value[0];
      bool ok = true;
      for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < i; ++j) {
          for (int k = 0; k < j; ++k) {
            int x = min(p[i], min(p[j], p[k]));
            int y = max(p[i], max(p[j], p[k]));
            if (value[x] + value[y] != a[i][j][k]) {
              ok = false;
            }
          }
        }
      }
      if (ok) {
        for (int i = 0; i < 5; ++i) {
          answer[i + start] = value[p[i]];
        }
      }
    } while (next_permutation(p.begin(), p.end()));
  };
  for (int i = 0; i < n; i += 5) {
    solve(min(i, n - 5));
  }
  cout << "!";
  for (int i = 0; i < n; ++i) {
    cout << " " << answer[i];
  }
  cout << endl;
  return 0;
}