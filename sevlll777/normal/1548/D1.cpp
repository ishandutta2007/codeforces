#include <iostream>
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
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>

#define pb push_back
#define int long long
#define all(x) x.begin(), (x).end()
#define rall(x) x.rbegin(), (x).rend()
#define ld long double
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  vector<int> X(n), Y(n);
  for (int i = 0; i < n; i++) {
    cin >> X[i] >> Y[i];
  }
  vector<int> cnt(4);
  for (int i = 0; i < n; i++) {
    int x1 = X[i] / 2 % 2, y1 = Y[i] / 2 % 2;
    cnt[x1 * 2 + y1]++;
  }
  int ans = 0;
  for (int i = 0; i < 4; i++) {
    if (cnt[i] >= 3) {
      ans += (cnt[i] * (cnt[i] - 1) * (cnt[i] - 2) / 6);
    }
  }
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (i != j && cnt[i] >= 2 && cnt[j] >= 1) {
        ans += (cnt[i] * (cnt[i] - 1) / 2) * cnt[j];
      }
    }
  }
  cout << ans << '\n';
}