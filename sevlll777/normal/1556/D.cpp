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

int ask(int i, int j) {
  int x, y;
  cout << "or " << i << ' ' << j << endl;
  cin >> x;
  cout << "and " << i << ' ' << j << endl;
  cin >> y;
  return x + y;
}

void solve() {
  int n, k;
  cin >> n >> k;
  int a1 = ask(1, 2), a2 = ask(2, 3), a3 = ask(1, 3);
  int s = (a1 + a2 + a3) / 2;
  vector<int> A(n + 1);
  A[1] = s - a2;
  A[2] = s - a3;
  A[3] = s - a1;
  for (int i = 4; i <= n; i++) {
    A[i] = ask(1, i) - A[1];
  }
  sort(all(A));
  cout << "finish " << A[k] << endl;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  while (t--) {
    solve();
  }
}