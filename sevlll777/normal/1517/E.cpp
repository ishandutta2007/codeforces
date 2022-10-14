#include <bits/extc++.h>

#define pb push_back
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ld long double
using namespace std;
const int M = 998244353;

using namespace __gnu_pbds;

typedef tree<
pair<int, int>,
null_type,
less<pair<int, int>>,
rb_tree_tag,
tree_order_statistics_node_update>
    ordered_set;

int bimbambam(vector<int> X, int b) {
  int n = (int) X.size() - 1;
  int sum = 0;
  for (auto x : X) sum += x;
  vector<int> P(n + 1), Q(n + 1);
  P[0] = 0;
  P[1] = X[1];
  Q[0] = 0;
  Q[1] = X[1];
  for (int i = 2; i <= n; i++) {
    P[i] = P[i - 1] + X[i];
    Q[i] = Q[i - 2] + X[i];
  }
  ordered_set even, odd;
  int ans = 0;
  int h = 2;
  for (int i = 0; i <= n; i++) {
    int val = sum - b;
    if (i) {
      val -= 2 * Q[i - 1];
    }
    if (i % 2 == 0) {
      ans += odd.order_of_key({val, -1});
      if (i) {      
        even.insert({2 * (P[i] - Q[i]), h++});
      }
    } else {
      ans += even.order_of_key({val, -1});
      odd.insert({2 * (P[i] - Q[i]), h++});
    }
  }

  return ans;

}

void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i = 0; i < n; i++) cin >> A[i];
  if (n == 1) {
    cout << "1\n";
    return;
  }
  if (n == 2) {
    if (A[0] == A[1]) {
      cout << "1\n";
    } else {
      cout << "2\n";
    }
    return;
  }

  int ans = 0;
  for (int s = 0; s <= 1; s++) {
    for (int f = 0; f <= 1; f++) {
      int b = 0;
      if (s == 1) {
        b -= A[0];
      }
      if (f == 1) {
        b += A[n - 1];
      }
      vector<int> X = {0};
      for (int i = s; i < n - f; i++) X.pb(A[i]);
      ans += bimbambam(X, b);
    }
  }

  int sum = 0;
  for (auto x : A) sum += x;
  int c = 0;
  for (int i = 0; i < n; i++) {
    c += A[i];
    if (c > sum - c) ans++;
  }

  ans %= M;
  cout << ans << '\n';

}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}