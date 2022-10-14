#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ld long double
using namespace std;
const int M = 1000000007;

void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i = 0; i < n; i++) cin >> A[i];
  vector<int> B(n - 1);
  for (int i = 0; i < n - 1; i++) {
    if (A[i + 1] > A[i]) {
      B[i] = 1;
    } else {
      B[i] = 0;
    }
  }
  vector<int> e(n), z(n);
  e[0] = 0;
  for (int i = 0; i < n - 1; i++) {
    if (B[i] == 1) {
      e[i + 1] = e[i] + 1;
    } else {
      e[i + 1] = 0;
    }
  }
  z[n - 1] = 0;
  for (int i = n - 2; i >= 0; i--) {
    if (B[i] == 0) {
      z[i] = z[i + 1] + 1;
    } else {
      z[i] = 0;
    }
  }

  for (int i = 0; i < n; i++) A[i] = n + 1 - A[i];
  B.assign(n - 1, 0);
  for (int i = 0; i < n - 1; i++) {
    if (A[i + 1] > A[i]) {
      B[i] = 1;
    } else {
      B[i] = 0;
    }
  }
  vector<int> e2, z2;
  e2.assign(n, 0);
  z2.assign(n, 0);
  e2[0] = 0;
  for (int i = 0; i < n - 1; i++) {
    if (B[i] == 1) {
      e2[i + 1] = e2[i] + 1;
    } else {
      e2[i + 1] = 0;
    }
  }
  z2[n - 1] = 0;
  for (int i = n - 2; i >= 0; i--) {
    if (B[i] == 0) {
      z2[i] = z2[i + 1] + 1;
    } else {
      z2[i] = 0;
    }
  }

  vector<int> C2(n);
  for (int i = 0; i < n; i++) {
    C2[i] = max(e2[i], z2[i]);
  }
  vector<int> pc2(n);
  pc2[0] = C2[0];
  for (int i = 1; i < n; i++) {
    pc2[i] = max(pc2[i - 1], C2[i]);
  }
  vector<int> sc2(n);
  sc2[n - 1] = C2[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    sc2[i] = max(sc2[i + 1], C2[i]);
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (e[i] && z[i] && e[i] == z[i] && e[i] % 2 == 0) {
      int x0 = i - e[i] - 1, x1 = i + z[i] + 1;
      bool ban = false;
      if (0 <= x0 && x0 < n && pc2[x0] >= e[i]) ban = true;
      if (0 <= x1 && x1 < n && sc2[x1] >= e[i]) ban = true;
      if (e2[i - e[i]] >= e[i]) ban = true;
      if (z2[i + z[i]] >= z[i]) ban = true;
      if (!ban) {
        ans++;
      }
    }
  }
  cout << ans << '\n';

}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();
}