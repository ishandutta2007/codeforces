#include <bits/extc++.h>

#ifndef DUMP
#define DUMP(...) (void)0
#endif

using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  auto sum = 0LL;
  for (int _ = n; _--;) {
    int64_t h;
    cin >> h;
    sum += h;
  }
  vector<int64_t> h(n);
  iota(begin(h), end(h), 0);
  sum -= accumulate(begin(h), end(h), 0LL);
  auto q = sum / n;
  for (auto&& e : h) e += q;
  sum %= n;
  for (int i = 0; i < n; ++i) {
    if (sum == 0) break;
    ++h[i];
    --sum;
  }
  for (int i = 0; i < n; ++i) {
    cout << h[i] << " \n"[i == n - 1];
  }
}