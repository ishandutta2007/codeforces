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
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ld long double
using namespace std;
int h, w;

pair<int, vector<vector<int>>> kek(vector<pair<int, int>> ob) {
  vector<vector<int>> F(h, vector<int>(w));
  int cnt = 0;
  for (auto p : ob) {
    int i = p.first, j = p.second;
    bool ban = false;
    for (int di = -1; di <= 1; di++) {
      for (int dj = -1; dj <= 1; dj++) {
        if (0 <= i + di && i + di < h && 0 <= j + dj && j + dj < w) {
          if (F[i + di][j + dj] == 1) {
            ban = true;
          }
        }
      }
    }
    if (!ban) {
      F[i][j] = 1;
      cnt++;
    }
  }
  return {cnt, F};
}

void solve() {
  cin >> h >> w;
  vector<pair<int, int>> ob;
  for (int i = 0; i < w; i++) {
    ob.pb({0, i});
  }
  for (int i = 1; i < h; i++) {
    ob.pb({i, w - 1});
  }
  for (int i = w - 2; i >= 0; i--) {
    ob.pb({h - 1, i});
  }
  for (int i = h - 2; i >= 1; i--) {
    ob.pb({i, 0});
  }
  int cnt = kek(ob).first;
  vector<vector<int>> F = kek(ob).second;
  for (int _ = 0; _ < 50; _++) {
    vector<pair<int, int>> ob2;
    for (int i = 1 ; i < (int) ob.size(); i++) {
      ob2.pb(ob[i]);
    }
    ob2.pb(ob[0]);
    if (kek(ob).first > cnt) {
      cnt = kek(ob).first;
      F = kek(ob).second;
    }
  }
  for (auto p : F) {
    for (auto x : p) {
      cout << x;
    }
    cout << '\n';
  }

  cout << '\n';
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