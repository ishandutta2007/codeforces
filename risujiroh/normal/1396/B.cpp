#include <bits/extc++.h>

#ifndef DUMP
#define DUMP(...) void(0)
#endif

using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto&& e : a) cin >> e;
    sort(begin(a), end(a));
    int sum = accumulate(begin(a), end(a), 0);
    if (2 * a.back() > sum or sum & 1) {
      cout << "T\n";
    } else {
      cout << "HL\n";
    }
  }
}