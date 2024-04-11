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

int ask(int i) {
  cout << "? " << i << endl;
  int ans;
  cin >> ans;
  return ans;
}

void solve() {
  int n;
  cin >> n;
  vector<bool> used(n + 1, false);
  vector<int> P(n + 1);
  for (int x = 1; x <= n; x++) {
    if (!used[x]) {
      int y = ask(x);
      int ory = y;
      while (true) {
        used[y] = true;
        int p = ask(x);
        P[y] = p;
        y = p;
        if (y == ory) break;
      }
    }
  }
  cout << "! ";
  for (int i = 1; i <= n; i++) {
    cout << P[i] << ' ';
  }
  cout << endl;
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