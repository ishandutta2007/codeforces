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
const int N = 4000009;
int f[N];
int lcd[N];
int sumf = 0;

vector<int> dels(int x) {
  if (x == 1) {
    return {1};
  }
  int l = lcd[x];
  int c = 0;
  while (x % l == 0) {
    x /= l;
    c++;
  }
  vector<int> dudka = dels(x);
  vector<int> ans;
  int kekw = 1;
  for (int c0 = 0; c0 <= c; c0++) {
    for (auto y : dudka) {
      ans.pb(y * kekw);
    }
    kekw *= l;
  }
  return ans;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  lcd[1] = 1;
  for (int i = 2; i < N; i++) {
    if (lcd[i] == 0) {
      for (int j = i; j < N; j += i) {
        lcd[j] = i;
      }
    }
  }
  f[1] = 1;
  sumf = 1;
  for (int i = 2; i <= n; i++) {
    f[i] = (sumf + (i > 2)) % m;
    int hueta = (2 * f[i - 1] + m - sumf) % m;
    for (auto d : dels(i)) {
      if (d != i && d != 1) {
        hueta += (f[d] + m - f[d - 1]);
        hueta %= m;
      }
    }
    f[i] += hueta;
    f[i] %= m;
    sumf += f[i];
    sumf %= m;
  }
  cout << f[n] << '\n';
}