#include <bits/stdc++.h>
using namespace std;

#ifndef LOCAL
#define cerr if(0) cerr
#endif

#define all(v) (v).begin(), (v).end()
template <class T> using vec = vector<T>;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n; cin >> n;
  vec<uint64_t> a(n); for (auto &i : a) cin >> i;
  sort(all(a));

  int64_t num = 1;
  
  auto of = [](uint64_t A, uint64_t B) {
    if ((A * B) / B == A) return true;
    return false;
  };

  auto binpow = [&](uint64_t A, uint64_t B) -> uint64_t {
    uint64_t res = 1;
    while (B) {
      if (B & 1) {
        if (of(res, A)) res *= A;
        else return 0;
      }
      if (of(A, A)) A = A * A;
      else return 0;
      B >>= 1;
    }
    return res;
  };

  int64_t mn = 9e18;
  while (binpow(num, n - 1) != 0) {
    int64_t cost = 0;
    for (int i = 0; i < n; ++i) {
      uint64_t aaa = binpow(num, i);
      if (aaa >= a[i]) cost += aaa - a[i];
      else cost += a[i] - aaa;
    }
    if (cost >= mn) {
      cout << mn;
      exit(0);
    }
    mn = cost;
    ++num;
  }

  cout << mn;
  return 0;
}