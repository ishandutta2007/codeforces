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
// #define int long long
#define p pair<int, int>
#define all(x) x.begin(), (x).end()
#define rall(x) x.rbegin(), (x).rend()
#define ld long double
using namespace std;
const int INF = 1000000009;

struct DO {
  vector<p > do_arr;
  int len;

  DO(vector<int> &a) {
    len = 1;
    while (len < a.size()) {
      len *= 2;
    }
    do_arr.assign(2 * len, {INF, -1});
    for (int q = len; q < len + a.size(); q++) {
      do_arr[q] = {a[q - len], q - len};
    }
    for (int q = len - 1; q > 0; q--) {
      do_arr[q] = min(do_arr[2 * q], do_arr[2 * q + 1]);
    }
  }

  void change(int q, int x) {
    do_arr[q + len].first = x;
    q = (q + len) / 2;
    while (q > 0) {
      do_arr[q] = min(do_arr[2 * q], do_arr[2 * q + 1]);
      q /= 2;
    }
  }

  p ans(int l, int r, int l1, int r1, int q) {
    if (l >= r1 || l1 >= r) {
      return {INF, -1};
    }
    if (l1 <= l && r <= r1) {
      return do_arr[q];
    }
    int m = (l + r) / 2;
    return min(ans(l, m, l1, r1, 2 * q), ans(m, r, l1, r1, 2 * q + 1));
  }
};

struct DO2 {
  vector<p > do_arr;
  int len;

  DO2(vector<int> &a) {
    len = 1;
    while (len < a.size()) {
      len *= 2;
    }
    do_arr.assign(2 * len, {-INF, -1});
    for (int q = len; q < len + a.size(); q++) {
      do_arr[q] = {a[q - len], q - len};
    }
    for (int q = len - 1; q > 0; q--) {
      do_arr[q] = max(do_arr[2 * q], do_arr[2 * q + 1]);
    }
  }

  void change(int q, int x) {
    do_arr[q + len].first = x;
    q = (q + len) / 2;
    while (q > 0) {
      do_arr[q] = max(do_arr[2 * q], do_arr[2 * q + 1]);
      q /= 2;
    }
  }

  p ans(int l, int r, int l1, int r1, int q) {
    if (l >= r1 || l1 >= r) {
      return {-INF, -1};
    }
    if (l1 <= l && r <= r1) {
      return do_arr[q];
    }
    int m = (l + r) / 2;
    return max(ans(l, m, l1, r1, 2 * q), ans(m, r, l1, r1, 2 * q + 1));
  }
};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> P(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> P[i];
    }
    vector<int> l(n + 1), r(n + 1);
    for (int i = 1; i <= n; i++) {
      l[i] = max(1, i - P[i]);
      r[i] = min(n, i + P[i]);
    }
    DO *do1 = new DO(l);
    DO2 *do2 = new DO2(r);
    deque<int> q = {a};
    vector<int> d(n + 1);
    d[a] = 0;
    do1->change(a, INF);
    do2->change(a, -INF);
    while (!q.empty()) {
      int v = q.front();
      q.pop_front();
      pair<int, int> t0 = do1->ans(0, do1->len, v + 1, r[v] + 1, 1);
      while (t0.first <= v) {
        q.pb(t0.second);
        d[t0.second] = d[v] + 1;
        do1->change(t0.second, INF);
        do2->change(t0.second, -INF);
        t0 = do1->ans(0, do1->len, v + 1, r[v] + 1, 1);
      }
      pair<int, int> t1 = do2->ans(0, do2->len, l[v], v, 1);
      while (t1.first >= v) {
        q.pb(t1.second);
        d[t1.second] = d[v] + 1;
        do1->change(t1.second, INF);
        do2->change(t1.second, -INF);
        t1 = do2->ans(0, do2->len, l[v], v, 1);
      }
    }
    cout << d[b] << '\n';
  }

}