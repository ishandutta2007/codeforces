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

void solve() {
  int n;
  cin >> n;
  vector<int> cnt1(26), cnt2(26), cnt3(1000);
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    cnt1[s[0] - 'a']++;
    cnt2[s[1] - 'a']++;
    cnt3[(s[0] - 'a') * 30 + (s[1] - 'a')]++;
  }
  int ans = 0;
  for (int i = 0; i < 26; i++) {
    ans += cnt1[i] * (cnt1[i] - 1) / 2;
  }
  for (int i = 0; i < 26; i++) {
    ans += cnt2[i] * (cnt2[i] - 1) / 2;
  }
  for (int i = 0; i < 1000; i++) {
    ans -= cnt3[i] * (cnt3[i] - 1);
  }
  cout << ans << '\n';
  return;
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