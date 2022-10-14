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

bool f(string t) {
  if (t.empty()) return true;
  sort(all(t));
  return !(t[0] == t[t.size() - 1]);
}

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  string t = "";
  for (auto c : s) {
    if (c != 'W') {
      t += c;
    } else {
      if (!f(t)) {
        cout << "NO\n";
        return;
      }
      t = "";
    }
  }
  if (!f(t)) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
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