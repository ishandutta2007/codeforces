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

struct op {
  int lock = 0;
  string color;
  bool unlocks = 0;

  op() = default;
  op(string c) {
    if (c == "lock")
      lock = 1;
    else if (c == "unlock")
      lock = -1;
    else
      color = c;
  }

  op operator+(const op &rhs) const {
    op res;
    res.lock = rhs.lock ? rhs.lock : lock;
    if (!rhs.color.empty() && (rhs.unlocks || lock != 1)) {
      res.color = rhs.color;
      if (rhs.unlocks || lock == -1)
        res.unlocks = true;
    } else if (!color.empty()) {
      res.color = color;
      res.unlocks = unlocks;
    }
    return res;
  }
};

const int N = 1 << 17;
op tr[N * 2];

void show() {
  if (tr[1].color.empty())
    cout << "blue\n";
  else
    cout << tr[1].color << '\n';
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  string s;
  rep(i, n) {
    cin >> s;
    tr[N + i] = s;
  }
  for (int i = N - 1; i > 0; --i)
    tr[i] = tr[i * 2] + tr[i * 2 + 1];
  int q, p;
  cin >> q;
  show();
  rep(i, q) {
    cin >> p >> s;
    --p;
    tr[N + p] = s;
    for (int j = (N + p) / 2; j; j /= 2)
      tr[j] = tr[j * 2] + tr[j * 2 + 1];
    show();
  }
}