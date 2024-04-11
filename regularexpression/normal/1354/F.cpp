#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int inf = (int) (1e9 + 7);

void solve() {
  int n, k;
  cin >> n >> k;
  vector <int> a(n), b(n), p(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    p[i] = i;
  }
  sort(p.begin(), p.end(), [&] (int x, int y) {
    return b[x] < b[y];
  });
  vector <vector <int>> dp(n + 1, vector <int>(k + 1, -inf));
  dp[0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= k; j++) {
      dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + b[p[i]] * (k - 1));
      if (j != k)
        dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + b[p[i]] * j + a[p[i]]);
    }
  }
  vector <int> v, u;
  int j = k;
  for (int i = n - 1; i > -1; i--) {
    if (dp[i + 1][j] == dp[i][j] + b[p[i]] * (k - 1))
      u.push_back(p[i]);
    else {
      v.push_back(p[i]);
      j--;
    }
  }
  reverse(v.begin(), v.end());
  cout << v.size() + u.size() * 2 << '\n';
  for (int i = 0; i + 1 < v.size(); i++)
    cout << v[i] + 1 << " ";
  for (auto x : u)
    cout << x + 1 << " " << -x - 1 << " ";
  cout << v.back() + 1 << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--)
    solve();
  return 0;
}