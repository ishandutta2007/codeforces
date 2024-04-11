#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, a, b, k;
  cin >> n >> a >> b >> k;
  int res = 0;
  multiset<int> ms;
  while (n--) {
    int h;
    cin >> h;
    h %= a + b;
    if (h == 0) {
      h = a + b;
    }
    if (1 <= h and h <= a) {
      ++res;
    } else {
      ms.insert((h - 1) / a);
    }
  }
  while (not ms.empty() and k >= *begin(ms)) {
    auto it = begin(ms);
    if (k >= *it) {
      k -= *it;
      ++res;
    }
    ms.erase(it);
  }
  cout << res << '\n';
}