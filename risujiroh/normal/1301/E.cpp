#include <bits/stdc++.h>
using namespace std;

const string col = "RGYB";

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, m, q;
  cin >> n >> m >> q;
  vector<string> s(n);
  for (auto&& e : s) {
    cin >> e;
  }
  vector<vector<vector<int>>> cnt(4, vector<vector<int>>(n + 1, vector<int>(m + 1)));
  for (int t = 0; t < 4; ++t) {
    for (int i = n; i--; ) {
      for (int j = m; j--; ) {
        cnt[t][i][j] = (s[i][j] == col[t]) + cnt[t][i][j + 1] + cnt[t][i + 1][j] - cnt[t][i + 1][j + 1];
      }
    }
  }
  vector<vector<vector<int>>> cum(min(n, m) / 2 + 1);
  for (int k = 1; k <= min(n, m) / 2; ++k) {
    cum[k].assign(n - 2 * k + 2, vector<int>(m - 2 * k + 2));
    for (int i = n - 2 * k; i >= 0; --i) {
      for (int j = m - 2 * k; j >= 0; --j) {
        bool ok = cnt[0][i][j] - cnt[0][i][j + k] - cnt[0][i + k][j] + cnt[0][i + k][j + k] == k * k and
                  cnt[1][i][j + k] - cnt[1][i][j + 2 * k] - cnt[1][i + k][j + k] + cnt[1][i + k][j + 2 * k] == k * k and
                  cnt[2][i + k][j] - cnt[2][i + k][j + k] - cnt[2][i + 2 * k][j] + cnt[2][i + 2 * k][j + k] == k * k and
                  cnt[3][i + k][j + k] - cnt[3][i + k][j + 2 * k] - cnt[3][i + 2 * k][j + k] + cnt[3][i + 2 * k][j + 2 * k] == k * k;
        cum[k][i][j] = ok + cum[k][i][j + 1] + cum[k][i + 1][j] - cum[k][i + 1][j + 1];
      }
    }
  }
  while (q--) {
    int li, lj, ri, rj;
    cin >> li >> lj >> ri >> rj;
    --li, --lj;
    int ok = 0, ng = min(ri - li, rj - lj) / 2 + 1;
    while (ng - ok > 1) {
      int mid = (ok + ng) / 2;
      (cum[mid][li][lj] - cum[mid][li][rj - 2 * mid + 1] - cum[mid][ri - 2 * mid + 1][lj] + cum[mid][ri - 2 * mid + 1][rj - 2 * mid + 1] ? ok : ng) = mid;
    }
    cout << 4 * ok * ok << '\n';
  }
}