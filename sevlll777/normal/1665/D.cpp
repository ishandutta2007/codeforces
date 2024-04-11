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
// #define int long long
#define all(x) x.begin(), (x).end()
#define rall(x) x.rbegin(), (x).rend()
#define ld long double
using namespace std;

// gcd(x+a, x+b) = gcd(x+a, b-a);
int g;

void ask(int a, int b) {
  cout << "? " << a << ' ' << b << endl;
  cin >> g;
}

void solve() {
  int a = 1, b = 2;
  int ans = 0;
  for (int p = 0; p < 30; p++) {
    ask(a, b + a);
    if (g != (1 << p)) {
      ans += (1 << p);
    } else {
      a += (1 << p);
    }
    b *= 2;
  }
  cout << "! " << ans << '\n';

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