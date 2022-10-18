#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    vector<int> a(N);
    map<int, int> cnt;
    for (int i = 0; i < N; ++i) {
      cin >> a[i];
      cnt[a[i]]++;
    }
    sort(a.begin(), a.end());
    if (N == 2) {
      if (a[0] < a[1]) {
        cout << 1 << "\n";
      } else {
        cout << 0 << "\n";
      }
      continue;
    }
    constexpr int kP = 998244353;

    auto fpow = [&](int a, int n) {
      int res = 1;
      while (n > 0) {
        if (n & 1) res = 1LL * res * a % kP;
        a = 1LL * a * a % kP;
        n >>= 1;
      }
      return res;
    };

    vector<int> fc(N + 1, 1), iv(N + 1, 1);
    for (int i = 1; i <= N; ++i) {
      fc[i] = 1LL * fc[i - 1] * i % kP;
      iv[i] = fpow(fc[i], kP - 2);
    }
    vector<pair<int, int>> vec;
    for (auto iter : cnt) {
      vec.emplace_back(iter.first, iter.second);
    }
    vector<vector<int>> dp(vec.size(), vector<int>(N / 2 + 1));
    for (int i = 0; i < vec.size(); ++i) {
      int p = lower_bound(a.begin(), a.end(), vec[i].first) - a.begin();
      int c = vec[i].second;
      dp[i][1] = 1LL * p * (p - 1) % kP * c % kP;
    }
    vector<int> sum(N / 2 + 1);
    for (int i = 0; i < vec.size(); ++i) {
      int p = lower_bound(a.begin(), a.end(), vec[i].first) - a.begin();
      int c = vec[i].second;
      for (int j = 2; j <= N / 2; ++j) {
        if (j < N / 2) {
          if (p >= j + j - 1) {
            dp[i][j] = 1LL * (p - j - j + 1) * sum[j - 1] % kP * c % kP;
          }
        } else {
          dp[i][j] = 1LL * sum[j - 1] * c % kP;
        }
      }
      for (int j = 1; j <= N / 2; ++j) {
        (sum[j] += dp[i][j]) %= kP;
      }
    }
    int ans = 0;
    for (int i = 0; i < vec.size(); ++i) {
      ans += dp[i][N / 2];
      ans %= kP;
    }
    for (auto iter : cnt) {
      ans = 1LL * ans * iv[iter.second] % kP;
    }
    cout << ans << "\n";
  }
}