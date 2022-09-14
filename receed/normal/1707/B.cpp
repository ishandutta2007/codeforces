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
  ios_base::sync_with_stdio(0); cin.tie(0);
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    deque<int> a(n), b;
    rep(i, n)
      cin >> a[i];
    int nn = n;
    rep(i, nn - 1) {
      b.resize(n - 1);
      rep(i, n - 1)
        b[i] = a[i + 1] - a[i];
      sort(all(b));
      while (b.size() > 1 && b[0] == 0)
        b.pop_front();
      if (b.size() < nn - i - 1 && b[0] != 0)
        b.push_front(0);
      swap(a, b);
      n = a.size();
      if (n == 1)
        break;
    }
    cout << a[0] << '\n';
  }
}