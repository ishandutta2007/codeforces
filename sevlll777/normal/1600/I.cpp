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


signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  ld p;
  cin >> p;
  for (ld x = 0; x <= n; x++) {
    ld a = x * (x - 1) * (x - 2) / 6;
    ld c = x * (n - x) * (n - x - 1) / 2;
    ld b = x * (x - 1) * (n - x) / 2;
    ld d = (n - x) * (n - x - 1) * (n - x - 2) / 6;
    ld kek = (a / (a + b + c + d)) + (b / (a + b + c + d)) + (c / (2 * (a + b + c + d)));
    if (kek >= p) {
      cout << x << '\n';
      break;
    }
  }
}