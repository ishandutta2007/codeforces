#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1505;

int n, g[N][N], row[N][N], col[N][N];

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      scanf("%d", g[i] + j);
    }
  }
  for (int i = 1; i <= n; ++i) {
    vector <int> id(n);
    for (int j = 0; j < n; ++j) id[j] = j + 1;
    sort(id.begin(), id.end(), [&] (int x, int y) {
      return g[i][x] < g[i][y];
    });
    for (int j = 0; j < n; ++j) row[i][id[j]] = j;
  }
  for (int i = 1; i <= n; ++i) {
    vector <int> id(n);
    for (int j = 0; j < n; ++j) id[j] = j + 1;
    sort(id.begin(), id.end(), [&] (int x, int y) {
      return g[x][i] < g[y][i];
    });
    for (int j = 0; j < n; ++j) col[id[j]][i] = j;
  }
  ll total = (ll) n * (n - 1) / 2, triples = 0;
  total *= total;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      triples += (ll) row[i][j] * col[i][j];
    }
  }
  cout << 2 * total - triples << '\n';
  return 0;
}