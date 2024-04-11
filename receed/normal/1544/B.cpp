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
  int t, h, w;
  cin >> t;
  while (t--) {
    cin >> h >> w;
    rep(i, h) {
      rep(j, w) {
        if ((i == 0 || i == h - 1) && j % 2 == 0 || (j == 0 || j == w - 1) && i > 0 && i < h - 2 && i % 2 == 0)
          cout << 1;
        else
          cout << 0;
      }
      cout << '\n';
    }
    cout << '\n';
  }
}