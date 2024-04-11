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
  V<> inva(n + 1);
  for (int i = 0; i < n; i++) inva[a[i]] = i;
  string res(n, 'C');
  for (int i = n; i; i--) {
    int s = inva[i];
    bool win = false;
    for (int j = s; j >= 0; j -= i) if (res[j] == 'B') win = true;
    for (int j = s; j < n; j += i) if (res[j] == 'B') win = true;
    res[s] = win ? 'A' : 'B';
  }
  cout << res << '\n';
}