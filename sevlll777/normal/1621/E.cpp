#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>

#define pb push_back
#define int long long
#define ld long double
#define all(x) x.begin(), (x).end()
#define rall(x) x.rbegin(), (x).rend()
#define ld long double
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> A(n);
  for (int i = 0; i < n; i++) cin >> A[i];
  sort(rall(A));
  while ((int) A.size() > m) A.pop_back();
  reverse(all(A));
  vector<vector<int>> B(m);
  vector<int> S(m);
  for (int g = 0; g < m; g++) {
    int k;
    cin >> k;
    for (int _ = 0; _ < k; _++) {
      int x;
      cin >> x;
      B[g].pb(x);
      S[g] += x;
    }
  }
  vector<ld> S0;
  for (int i = 0; i < m; i++) {
    S0.pb((ld) (S[i]) * 1.0 / (ld) B[i].size());
  }
  sort(all(S0));
  vector<int> C(m);
  vector<int> R(m);
  vector<int> L(m);
  for (int i = 0; i < m; i++) {
    C[i] = (A[i] >= S0[i]);
    if (i != m - 1) {
      R[i] = (A[i + 1] >= S0[i]);
    }
    if (i) {
      L[i] = (A[i - 1] >= S0[i]);
    }
  }
  vector<int> pR(m + 1);
  for (int i = 0; i < m; i++) {
    pR[i + 1] = pR[i] + R[i];
  }
  vector<int> pL(m + 1);
  pL[0] = L[0];
  for (int i = 1; i < m; i++) {
    pL[i] = pL[i - 1] + L[i];
  }
  int fr = m + 1;
  for (int y = 0; y < m; y++) {
    if (A[y] < S0[y]) {
      fr = y;
      break;
    }
  }
  int gr = -1;
  for (int y = m - 1; y >= 0; y--) {
    if (A[y] < S0[y]) {
      gr = y;
      break;
    }
  }
  sort(all(S0));
  for (int g = 0; g < m; g++) {
    for (auto x : B[g]) {
      ld s1 = ((ld) S[g] - x) * 1.0 / ((int) B[g].size() - 1);
      ld s0 = (ld) S[g] / ((int) B[g].size());
      int j = (upper_bound(all(S0), s1) - S0.begin());
      if ((S[g] - x) * (int) B[g].size() >= S[g] * ((int) B[g].size() - 1)) {
        j--;
      }
      int i = lower_bound(all(S0), s0) - S0.begin();
      bool ok = true;
      if (j > i) {
        ok &= (i <= fr);
        ok &= (j + 1 > gr);
        ok &= ((pL[j] - pL[i]) == (j - i));
      } else {
        ok &= (j <= fr);
        ok &= (i + 1 > gr);
        ok &= ((pR[i] - pR[j]) == (i - j));
      }
      ok &= (A[j] >= s1);
      if (ok) {
        cout << 1;
      } else {
        cout << 0;
      }
    }
  }
  cout << '\n';

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