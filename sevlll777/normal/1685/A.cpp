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
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (n % 2) {
    cout << "NO\n";
    return;
  }
  sort(all(a));
  vector<int> b(n);
  for (int i = 0; i < n / 2; i++) {
    b[2 * i] = a[i];
    b[2 * i + 1] = a[n / 2 + i];
  }
  for (int i = 0; i < n; i++) {
    if ((b[i] > b[(n + i - 1) % n] && b[i] > b[(i + 1) % n]) || (b[i] < b[(n + i - 1) % n] && b[i] < b[(i + 1) % n]))  {
    } else {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
  for (auto x : b) {
    cout << x << ' ';
  }
  cout << "\n";
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