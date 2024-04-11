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
#define all(x) x.begin(), (x).end()
#define rall(x) x.rbegin(), (x).rend()
#define ld long double
using namespace std;
const int N = (int) 1e12;
vector<int> F = {1};

int bb(int x) {
  int a = 0;
  for (int z = 60; z >= 0; z--) {
    if ((x >> z) & 1) {
      a++;
    }
  }
  return a;
}

void solve() {
  int n;
  cin >> n;
  int ans = N;
  for (int mask = 0; mask < (1LL << (int) F.size()); mask++) {
    int sas = 0;
    int cnt = 0;
    for (int i = 0; i < (int) F.size(); i++) {
      if ((mask >> i) & 1) {
        sas += F[i];
        cnt++;
      }
    }
    if (n >= sas) {
      ans = min(ans, cnt + bb(n - sas));
    }
  }
  if (ans == N) ans = -1;
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  for (int x = 2; x <= 20; x++) {
    if (x * F.back() <= N) {
      F.pb(x * F.back());
    } else {
      break;
    }
  }
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}