#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  string s; cin >> s;
  bitset<10> bs;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'L') {
      for (int j = 0; j < 10; ++j) if (!bs[j]) {
        bs[j] = 1;
        break;
      }
    } else if (s[i] == 'R') {
      for (int j = 10 - 1; j >= 0; --j) if (!bs[j]) {
        bs[j] = 1;
        break;
      }
    } else {
      int x = s[i] - '0';
      bs[x] = 0;
    }
  }
  for (int i = 0; i < 10; ++i) {
    cout << bs[i];
  }
  cout << '\n';
}