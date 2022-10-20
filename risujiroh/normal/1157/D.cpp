#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  lint n, k; cin >> n >> k;
  if (n < k * (k + 1) / 2) return cout << "NO" << '\n', 0;
  if (n == 4 and k == 2 or n == 8 and k == 3) return cout << "NO" << '\n', 0;
  cout << "YES" << '\n';
  if (k == 1) return cout << n << '\n', 0;
  lint s = (n - k * (k + 1) / 2) / k;
  V<lint> res(k);
  iota(begin(res), end(res), 1 + s);
  lint r = n - accumulate(begin(res), end(res), 0LL);
  if (r < k - 1) {
    for (int i = 0; i < r; ++i) {
      ++res[k + ~i];
    }
  } else {
    for (int i = 0; i < k - 2; ++i) {
      ++res[k + ~i];
    }
    ++res.back();
  }
  for (int i = 0; i < k; ++i) {
    cout << res[i] << " \n"[!(k + ~i)];
  }
}