#include <bits/stdc++.h>
using namespace std;

long long tmod(long long a, long long p) {
  return (a %= p) < 0 ? a + p : a;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  long long n, p;
  cin >> n >> p;
  vector<int> res;
  bool neg = false;
  while (n) {
    if (neg) {
      n = -n;
      res.push_back(tmod(n, p));
      n -= res.back();
      n /= p;
      n = -n;
    } else {
      res.push_back(n % p);
      n -= res.back();
      n /= p;
    }
    neg ^= true;
  }
  int d = res.size();
  cout << d << '\n';
  for (int i = 0; i < d; ++i) {
    cout << res[i] << " \n"[i == d - 1];
  }
}