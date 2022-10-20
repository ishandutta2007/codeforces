#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  using ll = long long;
  vector<ll> a(n);
  for (auto&& e : a) cin >> e;
  vector<int> b(n), cnt(n);
  for (auto&& e : b) {
    cin >> e;
    if (e != -1) {
      --e;
      ++cnt[e];
    }
  }
  queue<int> que;
  for (int i = 0; i < n; ++i) {
    if (cnt[i]) continue;
    que.push(i);
  }
  ll res = 0;
  vector<int> p, q;
  while (not empty(que)) {
    int i = que.front();
    que.pop();
    res += a[i];
    if (a[i] < 0) {
      q.push_back(i);
    } else {
      p.push_back(i);
      if (b[i] != -1) {
        a[b[i]] += a[i];
      }
    }
    if (b[i] != -1 and --cnt[b[i]] == 0) {
      que.push(b[i]);
    }
  }
  while (not empty(q)) {
    p.push_back(q.back());
    q.pop_back();
  }
  cout << res << '\n';
  for (int i = 0; i < n; ++i) {
    cout << p[i] + 1 << " \n"[i == n - 1];
  }
}