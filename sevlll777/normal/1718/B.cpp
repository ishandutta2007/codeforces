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
const int INF = (int) 2e9;
const int N = 75;
int fib[N];

void solve() {
  int k;
  cin >> k;
  int s = 0;
  vector<int> c(k);
  multiset<int> ms;
  for (int i = 0; i < k; i++) {
    cin >> c[i];
    s += c[i];
    ms.insert(c[i]);
  }
  int s2 = 0;
  int j = 0;
  for (int i = 0; i < N; i++) {
    s2 += fib[i];
    if (s2 == s) {
      j = i;
      break;
    }
    if (s2 > s) {
      cout << "NO\n";
      return;
    }
  }
  int adr = -1;
  for (int i = j; i >= 0; i--) {
    if (ms.empty()) {
      cout << "NO\n";
      return;
    }
    int x = *ms.rbegin();
    ms.erase(ms.find(x));
    if (x < fib[i]) {
      cout << "NO\n";
      return;
    }
    x -= fib[i];
    if (adr != -1) {
      ms.insert(adr);
    }
    adr = x;
  }
  cout << "YES\n";
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  fib[0] = 1;
  fib[1] = 1;
  for (int i = 2; i < N; i++) {
    fib[i] = fib[i - 1] + fib[i - 2];
  }
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}