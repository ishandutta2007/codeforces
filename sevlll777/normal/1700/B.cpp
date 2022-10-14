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
  string s;
  cin >> s;
  string t = "";
  for (auto c : s) {
    t += (char) ('9' - (c - '0'));
  }
  if (s[0] == '9') {
    int cr = 0;
    for (int i = n - 1; i >= 0; i--) {
      if (cr == 0) {
        if (t[i] != '9') {
          t[i]++;
        } else {
          t[i] = '0';
          cr = 1;
        }
      } else {
        if (t[i] == '9') {
          t[i] = '1';
        } else if (t[i] == '8') {
          t[i] = '0';
        } else {
          t[i] += 2;
          cr = 0;
        }
      }
    }
    for (int i = n - 1; i >= 0; i--) {
      if (t[i] != '9') {
        t[i]++;
        for (int j = i + 1; j < n; j++) {
          t[j] = '0';
        }
        break;
      }
    }
  }
  cout << t << '\n';
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