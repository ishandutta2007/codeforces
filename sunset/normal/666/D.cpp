#include <bits/stdc++.h>

using namespace std;

const vector<int> dx = {0, 0, 1, 1};
const vector<int> dy = {0, 1, 1, 0};

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    vector<int> x(4), y(4);
    for (int i = 0; i < 4; ++i) {
      cin >> x[i] >> y[i];
    }
    vector<int> all;
    for (int i = 0; i < 4; ++i) {
      for (int j = i + 1; j < 4; ++j) {
        all.push_back(abs(x[i] - x[j]));
        all.push_back(abs(y[i] - y[j]));
      }
    }
    vector<int> ans_x(4), ans_y(4);
    int ans = 1 << 30;
    for (int d : all) {
      vector<pair<int, int>> points;
      for (int i = 0; i < 4; ++i) {
        for (int ii = 0; ii < 2; ++ii) {
          for (int j = 0; j < 4; ++j) {
            for (int jj = 0; jj < 2; ++jj) {
              points.emplace_back(x[i] - ii * d, y[j] - jj * d);
            }
          }
        }
      }
      vector<int> p(4);
      for (int i = 0; i < 4; ++i) {
        p[i] = i;
      }
      do {
        vector<int> xx(4), yy(4);
        for (int i = 0; i < 4; ++i) {
          xx[i] = x[p[i]] - dx[i] * d;
          yy[i] = y[p[i]] - dy[i] * d;
        }
        if (*min_element(xx.begin(), xx.end()) == *max_element(xx.begin(), xx.end())) {
          points.emplace_back(xx[0], (*max_element(yy.begin(), yy.end()) + *min_element(yy.begin(), yy.end())) / 2);
        }
        if (*min_element(yy.begin(), yy.end()) == *max_element(yy.begin(), yy.end())) {
          points.emplace_back((*max_element(xx.begin(), xx.end()) + *min_element(xx.begin(), xx.end())) / 2, yy[0]);
        }
      } while (next_permutation(p.begin(), p.end()));
      for (auto to : points) {
        int to_x = to.first, to_y = to.second;
        vector<int> p(4);
        for (int i = 0; i < 4; ++i) {
          p[i] = i;
        }
        do {
          vector<int> goes(4);
          bool valid = true;
          for (int i = 0; i < 4; ++i) {
            int x0 = to_x + dx[i] * d, y0 = to_y + dy[i] * d;
            int x1 = x[p[i]], y1 = y[p[i]];
            if (x0 == x1) {
              goes[i] = abs(y0 - y1);
            } else if (y0 == y1) {
              goes[i] = abs(x0 - x1);
            } else {
              valid = false;
              break;
            }
          }
          if (valid) {
            int res = *max_element(goes.begin(), goes.end());
            if (ans > res) {
              ans = res;
              for (int i = 0; i < 4; ++i) {
                ans_x[p[i]] = to_x + dx[i] * d;
                ans_y[p[i]] = to_y + dy[i] * d;
              }
            }
          }
        } while (next_permutation(p.begin(), p.end()));
      }
    }
    if (ans == 1 << 30) {
      cout << -1 << "\n";
    } else {
      cout << ans << "\n";
      for (int i = 0; i < 4; ++i) {
        cout << ans_x[i] << " " << ans_y[i] << "\n";
      }
    }
  }
  return 0;
}