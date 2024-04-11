#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... U> void assign(V<T>& v, int n, const U&... u) { v.resize(n); for (auto&& i : v) assign(i, u...); }

int main() {
  cin.tie(NULL); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<> a(n); for (int i = 0; i < n; i++) cin >> a[i];
  int neg = 0;
  for (int i = 0; i < n; i++) neg += a[i] < 0;
  if (neg & 1) {
    int mn = 2e9;
    for (int i = 0; i < n; i++) if (a[i] < 0) mn = min(mn, abs(a[i]));
    for (int i = 0; i < n; i++) if (a[i] < 0 and abs(a[i]) == mn) {
      a[i] = 0;
      break;
    }
  }
  V<> zi, nzi;
  for (int i = 0; i < n; i++) {
    if (!a[i]) zi.push_back(i);
    else nzi.push_back(i);
  }
  int lz = zi.size(), lnz = nzi.size();
  for (int i = 0; i < lz - 1; i++) {
    cout << 1 << ' ' << zi[i] + 1 << ' ' << zi[i + 1] + 1 << '\n';
  }
  if (lz and lnz) cout << 2 << ' ' << zi.back() + 1 << '\n';
  for (int i = 0; i < lnz - 1; i++) {
    cout << 1 << ' ' << nzi[i] + 1 << ' ' << nzi[i + 1] + 1 << '\n';
  }
}