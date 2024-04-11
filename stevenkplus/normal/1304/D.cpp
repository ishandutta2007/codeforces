#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n;
    string s;
    cin >> n >> s;
    int i = 0;
    while (i < n) {
      vector<int> v;
      v.push_back(i);
      while (i + 1 < n && s[i] == '<') {
        ++i;
        v.push_back(i);
      }
      ++i;
      reverse(v.begin(), v.end());
      for (int k: v) {
        cout << n - k << " ";
      }
    }
    cout << "\n";
    int x = 1, y = n;
    for (int i = 0; i < n; ++i) {
      if (i < n && s[i] == '<') {
        cout << x << " ";
        ++x;
      } else {
        cout << y << " ";
        --y;
      }
    }
    cout << "\n";
  }
}