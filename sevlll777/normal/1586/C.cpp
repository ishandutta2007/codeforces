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
// #define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ld long double
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<string> A(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  vector<int> kek(m);
  for (int j = 0; j < m - 1; j++) {
    for (int i = 1; i < n; i++) {
      if (A[i][j] == 'X' && A[i - 1][j + 1] == 'X') {
        kek[j] = 1;
        break;
      }
    }
  }
  for (int j = 1; j < m; j++) {
    kek[j] += kek[j - 1];
  }
  int qu;
  cin >> qu;
  while (qu--) {
    int l, r;
    cin >> l >> r;
    l--;
    r--;
    if (l == r) {
      cout << "YES\n";
    } else {
      r--;
      int jij = 0;
      if (l > 0) {
        jij = kek[l - 1];
      }
      if (kek[r] == jij) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    }
  }

}