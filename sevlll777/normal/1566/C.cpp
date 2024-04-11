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
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>

#define pb push_back
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ld long double
using namespace std;

int count(string a) {
  int kek = 0;
  bool is0 = false, is1 = false;
  int cnt0 = 0;
  for (auto c : a) {
    is0 |= (c == '0');
    cnt0 += (c == '0');
    is1 |= (c == '1');
    if (is0 && is1) {
      kek += 2;
      kek += cnt0 - 1;
      cnt0 = 0;
      is0 = false;
      is1 = false;
    }
  }
  kek += cnt0;
  return kek;
}

void solve() {
  int n;
  cin >> n;
  string a, b;
  cin >> a >> b;
  string a2;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == b[i]) {
      a2 += a[i];
    } else {
      ans += 2;
      ans += count(a2);
      a2 = "";
    }
  }
  ans += count(a2);
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