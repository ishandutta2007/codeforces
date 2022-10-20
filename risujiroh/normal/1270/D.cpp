#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  n = k + 1;
  map<int, int> mp;
  for (int p = 0; p < n; ++p) {
    cout << '?';
    for (int i = 0; i < n; ++i) {
      if (i != p) {
        cout << ' ' << i + 1;
      }
    }
    cout << endl;
    int pos, a;
    cin >> pos >> a;
    ++mp[a];
  }
  cout << "! " << prev(end(mp))->second << endl;
}