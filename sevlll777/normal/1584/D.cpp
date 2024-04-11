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
#define ld long double
#define all(x) x.begin(), (x).end()
#define rall(x) x.rbegin(), (x).rend()
#define ld long double
using namespace std;

int ask(int l, int r) {
  cout << "? " << l << ' ' << r << endl;
  int ans;
  cin >> ans;
  return ans;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int l = 1, r = n;
    while (r - l > 1) {
      int m = (l + r) / 2;
      if (ask(1, m) == 0) {
        l = m;
      } else {
        r = m;
      }
    }
    int i = l;
    int kek = ask(i, n) - ask(i + 1, n);
    int j = i + kek + 1;
    int x = ask(1, n);
    int y = 2 * x - (j - i) * (j - i - 1);
    y += j - j * j;
    int d = (1 - 2 * j) * (1 - 2 * j) + 4 * y;
    int s = (int) round(sqrt(d));
    cout << "! " << i << ' ' << j << ' ' << ((2 * j - 1) + s) / 2 << endl;
  }

}