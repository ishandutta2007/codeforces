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
  int n, a, b, c;
  cin >> n >> a >> b >> c;
  string s;
  cin >> s;
  bool f = true;
  int z = 0;
  int kik = 0;
  int did = 0;
  vector<int> Z;
  for (auto c : s) {
    if (c == '1') {
      if (f) {
        kik += max(0LL, z - 1);
        did += z;
        z = 0;
        f = false;
      } else {
        Z.pb(z);
        z = 0;
      }
    } else {
      z++;
    }
  }
  sort(all(Z));
  int ans = 0;
  if (!Z.empty() && Z.back() >= 2) {
    ans = a;
  }
  if (kik >= 1 || z >= 2) {
    ans = a;
  }
  kik += max(0LL, z - 1);
  did += z;
  int sum = 0;
  int cnt0 = 0;
  vector<int> G((int) Z.size() + 1);
  vector<int> D((int) Z.size() + 1);
  D[(int) Z.size()] = did;
  G[(int) Z.size()] = kik;
  for (int i = (int) Z.size() - 1; i >= 0; i--) {
    G[i] = G[i + 1] + max(0LL, Z[i] - 1);
    D[i] = D[i + 1] + Z[i];
  }
  for (int i = 0; i < (int) Z.size(); i++) {
    sum += Z[i];
    cnt0 += (Z[i] == 0);
    if (sum <= i + 1) {
      if (sum + G[i + 1] >= i) {
        int score = b * (i + 1);
        score -= c * (i + 1 - cnt0);
        score += a * (sum - (i + 1 - cnt0));
        score += a * min(G[i + 1], i + 2 - sum);
        ans = max(ans, score);
      } else if (sum + D[i + 1] >= i) {
        int score = b * (i + 1);
        score -= c * (i + 1 - cnt0);
        score += a * (sum - (i + 1 - cnt0));
        score += a * G[i + 1];
        int rest = i - sum - G[i + 1];
        score -= c * rest;
        ans = max(ans, score);
      }
    }
  }
  cout << ans;
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