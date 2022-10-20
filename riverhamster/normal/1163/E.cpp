#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> basis(18);

bool insert(int x) {
  for (int i = 17; i >= 0; --i) {
    if (~(x >> i) & 1) continue;
    if (basis[i]) x ^= basis[i];
    else {
      basis[i] = x;
      return true;
    }
  }
  return false;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &x : a) cin >> x;
  sort(a.begin(), a.end());
  int high = 0;
  vector<int> b;
  int res = 0, pos = 0;
  for (int i = 0; i < n; ++i) {
    while (a[i] >> (high + 1)) ++high;
    if (insert(a[i])) {
      b.push_back(a[i]);
      if (high + 1 == (int)b.size()) res = b.size(), pos = i;
    }
  }
  cout << res << endl;
  fill(basis.begin(), basis.end(), 0);
  b.clear(); high = 0;
  for (int i = 0; i <= pos; ++i) {
    while (a[i] >> (high + 1)) ++high;
    if (insert(a[i])) b.push_back(a[i]);
  }
  vector<int> grey((1 << res));
  for (int i = 1; i <= res; ++i) {
    for (int j = 1 << (i - 1); j < (1 << i); ++j)
      grey[j] = grey[(1 << i) - 1 - j] | (1 << (i - 1));
  }
  cout << 0 << ' ';
  int xs = 0;
  for (int i = 1; i < (1 << res); ++i) {
    int p = __builtin_ctz(grey[i] ^ grey[i - 1]);
    xs ^= b[p];
    cout << xs << ' ';
  }
  cout << endl;
  return 0;
}