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
// #define int long long
#define ld long double
#define all(x) x.begin(), (x).end()
#define rall(x) x.rbegin(), (x).rend()
#define ld long double
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, d;
  cin >> n >> d;
  vector<int> p(n);
  vector<int> cnt(n, 1);
  for (int i = 0; i < n; i++) p[i] = i;
  int free = 0;
  while (d--) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    if (p[x] == p[y]) {
      free++;
    } else {
      int pup = p[x];
      for (int i = 0; i < n; i++) {
        if (p[i] == pup) {
          cnt[p[i]]--;
          p[i] = p[y];
          cnt[p[y]]++;
        }
      }
    }
    vector<int> cnt2 = cnt;
    sort(rall(cnt2));
    int ans = 0;
    for (int i = 0; i <= free; i++) {
      ans += cnt2[i];
    }
    cout << ans - 1 << '\n';
  }

}