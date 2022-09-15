#include <iostream>

using namespace std;

const int maxn = 5000;

int a[maxn][maxn + 1], fz[maxn];

// a[pos][length]

int main() {
  ios_base::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;

  string s;
  for (int i = 0; i < n; ++i) {
    cin >> s;
    for (int j = m - 1; j >= 0; --j)
      if (j == m - 1)
        fz[j] = s[j] == '0' ? j : m;
      else
        fz[j] = s[j] == '0' ? j : fz[j + 1];

    for (int j = 0; j < m; ++j) a[j][fz[j] - j] += 1;
  }

  // for (int i = 0; i < n; ++i) {
  //   for (int j = 0; j <= m; ++j) cout << a[i][j] << ' ';
  //   cout << '\n';
  // }

  for (int pos = 0; pos < m; ++pos)
    for (int length = m - 1; length >= 0; --length)
      a[pos][length] += a[pos][length + 1];

  int ans = 0;
  for (int pos = 0; pos < m; ++pos)
    for (int length = 0; length <= m; ++length)
      ans = max(ans, length * a[pos][length]);

  cout << ans << '\n';

  return 0;
}