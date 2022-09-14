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

const int N = 100001;
int a[N];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, q, s = 0;
  cin >> n >> q;
  rep(i, n) {
    cin >> a[i];
    s += a[i];
  }
  int t, x;
  rep(i, q) {
    cin >> t >> x;
    if (t == 1) {
      x--;
      s += 1 - 2 * a[x];
      a[x] = 1 - a[x];
    } else {
      if (x <= s)
        cout << "1\n";
      else
        cout << "0\n";
    }
  }
}