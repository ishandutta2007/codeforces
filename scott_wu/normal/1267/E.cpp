#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int MAXN = 110;
int mat[MAXN][MAXN];

typedef pair<int, int> pii;
vector<pii> ansr;

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    for(int j = 0; j < n; ++j) {
      cin >> mat[i][j];
    }
  }

  int ans = m + 1;
  vector<pii> ar(m);
  for(int i = 0; i < n - 1; ++i) {
    int sum = 0;
    for(int j = 0; j < m; ++j) {
      ar[j].second = j + 1;
      ar[j].first = mat[j][i] - mat[j][n - 1];
      sum += ar[j].first;
    }
    sort(ar.begin(), ar.begin() + m);
    int cnt = 0;
    for(int j = 0; sum < 0; ++j) {
      sum -= ar[j].first;
      ++cnt;
    }
    if (cnt < ans) {
      ans = cnt;
      ansr = ar;
    }
  }
  cout << ans << "\n";
  for(int i = 0; i < ans; ++i) {
    cout << ansr[i].second << " ";
  }
  cout << "\n";
}