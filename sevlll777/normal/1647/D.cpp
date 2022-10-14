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

bool prime(int x) {
  if (x == 1) {
    return true;
  }
  for (int d = 2; d * d <= x; d++) {
    if (x % d == 0) {
      return false;
    }
  }
  return true;
}

void solve() {
  int x, d;
  cin >> x >> d;
  if (x % (d * d) == 0) {
    if (prime(d)) {
      while (x % d == 0) {
        x /= d;
      }
      if (prime(x)) {
        cout << "NO\n";
      } else {
        cout << "YES\n";
      }
    } else {
      int num = x / (d * d);
      if (prime(num)) {
        cout << "NO\n";
      } else {
        if (d <= 200 && (x % (d * d * d * d) == 0)) {
          cout << "YES\n";
        } else if (x % (d * d * d) == 0) {
          int w = x / (d * d * d);
          if (!prime(w)) {
            cout << "YES\n";
          } else {
            w *= d;
            bool ok = false;
            for (int a = 1; a * a <= w; a++) {
              if ((w % a == 0) && (a % d) && ((w / a) % d)) {
                ok = true;
              }
            }
            if (ok) {
              cout << "YES\n";
            } else {
              cout << "NO\n";
            }
          }
        } else {
          int cnt = 0;
          for (int a = 1; a * a <= num; a++) {
            if ((num % a == 0) && (a % d) && ((num / a) % d)) {
              cnt++;
            }
          }
          if (cnt >= 2) {
            cout << "YES\n";
          } else {
            cout << "NO\n";
          }
        }
      }
    }
  } else {
    cout << "NO\n";
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