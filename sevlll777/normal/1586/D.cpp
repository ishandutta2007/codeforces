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
  int pn = 1;
  for (int x = 2; x <= n; x++) {
    cout << "? ";
    for (int _ = 0; _ < n - 1; _++) cout << x << ' ';
    cout << 1 << endl;
    int k;
    cin >> k;
    if (k != 0) {
      pn++;
    } else {
      break;
    }
  }
  vector<int> P(n + 1);
  P[n] = pn;
  for (int z = pn + 1; z <= n; z++) {
    cout << "? ";
    for (int _ = 0; _ < n - 1; _++) cout << "1 ";
    cout << z - pn + 1 << endl;
    int k;
    cin >> k;
    P[k] = z;
  }
  for (int z = 1; z < pn; z++) {
    cout << "? ";
    for (int _ = 0; _ < n - 1; _++) cout << pn + 1 - z << ' ';
    cout << 1 << endl;
    int k;
    cin >> k;
    P[k] = z;
  }
  cout << "! ";
  for (int x = 1; x <= n; x++) {
    cout << P[x] << ' ';
  }
  cout << endl;
}