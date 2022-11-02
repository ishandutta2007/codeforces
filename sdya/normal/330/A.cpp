#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector < string > s(n);
  vector < bool > a(n), b(m);
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
    for (int j = 0; j < m; ++j) {
      if (s[i][j] != '.') {
        a[i] = true;
        b[j] = true;
      }
    }
  }
  cout << n * m - count(a.begin(), a.end(), true) * count(b.begin(), b.end(), true) << endl;
  return 0;
}