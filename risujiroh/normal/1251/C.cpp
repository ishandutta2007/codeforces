#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int q; cin >> q;
  while (q--) {
    string s; cin >> s;
    string odd, even;
    for (char c : s) {
      if ((c - '0') & 1) {
        odd += c;
      } else {
        even += c;
      }
    }
    int n = odd.size(), m = even.size();
    string res;
    int i = 0, j = 0;
    while (i < n or j < m) {
      if (i == n) {
        res += even[j++];
      } else if (j == m) {
        res += odd[i++];
      } else if (odd[i] < even[j]) {
        res += odd[i++];
      } else {
        res += even[j++];
      }
    }
    cout << res << '\n';
  }
}