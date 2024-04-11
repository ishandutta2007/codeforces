#include <bits/stdc++.h>

using namespace std;

const int N = 300;

struct point {
  int x, y;

  point(int x = 0, int y = 0): x(x), y(y) {
  }

  point operator - (const point &other) const {
    return point(x - other.x, y - other.y);
  }

  long long operator * (const point &other) const {
    return (long long) x * other.y - (long long) y * other.x;
  }
};

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<point> p(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i].x >> p[i].y;
  }
  vector<vector<bitset<N>>> left(n, vector<bitset<N>>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (j != i) {
        for (int k = 0; k < n; ++k) {
          if (k != i && k != j) {
            left[i][j][k] = (p[j] - p[i]) * (p[k] - p[i]) > 0;
          }
        }
      }
    }
  }
  long long foo = 0, bar = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      for (int k = i + 1; k < n; ++k) {
        if (left[i][j][k]) {
          int inside = (left[i][j] & left[j][k] & left[k][i]).count();
          foo += inside;
          bar += inside * (inside - 1) / 2;
        }
      }
    }
  }
  cout << (long long) n * (n - 1) * (n - 2) * (n - 3) * (n - 4) / 120 - foo * (n - 4) / 2 + bar << "\n";
  return 0;
}