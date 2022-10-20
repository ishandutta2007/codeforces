#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, t; cin >> n >> t;
  int res = -1, mn = 1e9;
  for (int i = 1; i <= n; ++i) {
    int s, d; cin >> s >> d;
    int curr = -1; 
    if (t < s) curr = s;
    else curr = s + (t - s + d - 1) / d * d;
    if (curr < mn) {
      mn = curr;
      res = i;
    }
  }
  cout << res << '\n';
}