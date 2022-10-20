#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  string s; cin >> s;
  V<> a(n), b(n); for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];
  V< bitset<1 << 10> > bs(n);
  for (int i = 0; i < n; ++i) {
    for (int t = 0; t < b[i]; ++t) {
      bs[i][t] = s[i] == '1';
    }
    for (int t = b[i]; t < 1 << 10; ++t) {
      bs[i][t] = t % a[i] == b[i] % a[i] ? !bs[i][t - 1] : bs[i][t - 1]; 
    }
  }
  int res = 0;
  for (int t = 0; t < 1 << 10; ++t) {
    int curr = 0;
    for (int i = 0; i < n; ++i) curr += bs[i][t];
    res = max(res, curr);
  }
  cout << res << '\n';
}