#include <bits/stdc++.h>

using namespace std;

vector<int> stable_marriage(int n, vector<vector<int>> man, vector<vector<int>> woman) {
  vector<vector<int>> index(n, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      index[i][woman[i][j]] = j;
    }
  }
  vector<int> ans(n * 2, -1);
  vector<bool> free(n, true);
  int cnt = n;
  auto engage = [&](int m, int w) {
    ans[m] = w + n;
    ans[w + n] = m;
    free[m] = false;
  };
  while (true) {
    int m = 0;
    while (m < n && !free[m]) {
      m++;
    }
    if (m == n) {
      break;
    }
    for (int i = 0; i < n; ++i) {
      int w = man[m][i];
      if (ans[w + n] == -1) {
        engage(m, w);
        --cnt;
        break;
      } else {
        int mm = ans[w + n];
        if (index[w][m] < index[w][mm]) {
          free[mm] = true;
          ans[mm] = -1;
          engage(m, w);
          break;
        }
      }
    }
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> a[i][j];
      }
    }
    cout << "B" << endl;
    string type;
    int start;
    cin >> type >> start;
    int sign = (type == "I") == (start <= n) ? 1 : -1;
    vector<vector<int>> man(n, vector<int>(n)), woman(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        man[i][j] = woman[i][j] = j;
      }
      sort(man[i].begin(), man[i].end(), [&](int x, int y) {
        return sign * a[i][x] < sign * a[i][y];
      });
      sort(woman[i].begin(), woman[i].end(), [&](int x, int y) {
        return sign * a[x][i] > sign * a[y][i];
      });
    }
    vector<int> ans = stable_marriage(n, man, woman);
    while (start != -1) {
      cout << ans[start - 1] + 1 << endl;
      cin >> start;
    }
  }
  return 0;
}