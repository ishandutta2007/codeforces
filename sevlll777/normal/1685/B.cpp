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
  int a, b, c, d;
  string s;
  cin >> a >> b >> c >> d >> s;
  int n = a + b + 2 * c + 2 * d;
  int ca = 0;
  for (auto x : s) {
    ca += (x == 'A');
  }
  if (ca != a + c + d) {
    cout << "NO\n";
    return;
  }
  vector<int> bc, bd;
  int kek = 0;
  int cntc = 0, cntd = 0;
  string t;
  t += s[0];
  for (int i = 1; i < n; i++) {
    if (s[i] != s[i - 1]) {
      t += s[i];
    } else {
      if ((int) t.size() % 2 == 1) {
        kek += (int) t.size() / 2;
      } else {
        if (t[0] == 'A') {
          cntc += (int) t.size() / 2;
          bc.pb((int) t.size() / 2 - 1);
        } else {
          cntd += (int) t.size() / 2;
          bd.pb((int) t.size() / 2 - 1);
        }
      }
      t = s[i];
    }
  }
  if ((int) t.size() % 2 == 1) {
    kek += (int) t.size() / 2;
  } else {
    if (t[0] == 'A') {
      cntc += (int) t.size() / 2;
      bc.pb((int) t.size() / 2 - 1);
    } else {
      cntd += (int) t.size() / 2;
      bd.pb((int) t.size() / 2 - 1);
    }
  }
  if (max(0LL, c - cntc) + max(0LL, d - cntd) <= kek) {
    cout << "YES\n";
  } else {
    if (c >= cntc && d >= cntd) {
      cout << "NO\n";
    } else if (c <= cntc) {
      int rest = d - kek - cntd;
      cntc -= rest;
      sort(rall(bc));
      for (int i = 0; i < bc.size(); i++) {
        if (rest > bc[i]) {
          cntc--;
          rest -= bc[i];
        } else {
          cntc--;
          break;
        }
      }
      if (cntc >= c) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    } else {
      int rest = c - kek - cntc;
      cntd -= rest;
      sort(rall(bd));
      for (int i = 0; i < bd.size(); i++) {
        if (rest > bd[i]) {
          cntd--;
          rest -= bd[i];
        } else {
          cntd--;
          break;
        }
      }
      if (cntd >= d) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    }
  }
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