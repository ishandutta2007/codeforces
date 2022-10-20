#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  constexpr int lim = 1e5;
  vector<int> cnt(lim);
  multiset<int> ms;
  for (int _ = lim; _--; ) {
    ms.insert(0);
  }
  int sum = 0;
  auto add = [&](int x) {
    sum -= cnt[x] / 2;
    ms.erase(ms.find(cnt[x]));
    ++cnt[x];
    sum += cnt[x] / 2;
    ms.insert(cnt[x]);
  };
  auto remove = [&](int x) {
    sum -= cnt[x] / 2;
    ms.erase(ms.find(cnt[x]));
    --cnt[x];
    sum += cnt[x] / 2;
    ms.insert(cnt[x]);
  };
  int n;
  cin >> n;
  while (n--) {
    int x;
    cin >> x;
    --x;
    add(x);
  }
  int q;
  cin >> q;
  while (q--) {
    char c;
    cin >> c;
    int x;
    cin >> x;
    --x;
    if (c == '+') {
      add(x);
    } else {
      remove(x);
    }
    if (*rbegin(ms) >= 4 and sum >= 4) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}