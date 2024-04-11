#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <random>
#include <bitset>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ul = unsigned long long;
using ld = long double;

int f;

void go(vector<int> &a, int p, int s) {
  if (p == a.size()) {
    if (s == 0)
      f++;
    return;
  }
  for (int i = -1; i <= 1; ++i)
    go(a, p + 1, s + i * a[p]);
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<int> a(n);
    rep(i, n)
      cin >> a[i];
    f = 0;
    go(a, 0, 0);
    if (f > 1)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}