#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (auto&& e : a) {
      cin >> e;
    }
    long long s = accumulate(begin(a), end(a), 0LL);
    long long t = accumulate(begin(a), end(a), 0LL, [](long long x, long long y) { return x ^ y; });
    cout << "2 " << t << ' ' << s + t << '\n';
  }
}