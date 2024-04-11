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

int main() {
  int n, k, fl = 0;
  cin >> n >> k;
  if (k % 2 == 0 && n % 2) {
    cout << "-1" << endl;
    return 0;
  }
  if (n % 2 == 0 && k % 2 && k * 2 > n) {
    k = n - k;
    fl = 1;
  }
  int c = 1;
  while (c * k < n || c * k % 2 != n % 2 || c == 2 && c * k > n)
    ++c;
  int x = (c * k - n) / 2;
  vector<int> ord;
  rep(i, x)
    ord.push_back(i);
  int r = x;
  assert(x <= n);
  assert(x == 0 || (n - x) / 2 + x >= k);
  rep(i, (n - x) / 2)
    ord.push_back(r++);
  rep(i, x)
    ord.push_back(i);
  rep(i, (n - x + 1) / 2)
    ord.push_back(r++);
  rep(i, x)
    ord.push_back(i);
  ll ans = 0, res;
  for (int i = 0; i < ord.size(); i += k) {
    cout << "?";
    if (fl) {
      vector<int> dd(n, 1);
      for (int j = i; j < i + k; ++j)
        dd[ord[j]] = 0;
      rep(j, n)
        if (dd[j])
          cout << ' ' << j + 1;
    } else {
      for (int j = i; j < i + k; ++j)
        cout << ' ' << ord[j] + 1;
    }
    cout << endl;
    cin >> res;
    ans ^= res;
  }
  cout << "! " << ans << endl;
}