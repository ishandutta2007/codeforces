#include <bits/extc++.h>

#ifndef DUMP
#define DUMP(...) (void)0
#endif

using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  char op = '+';
  vector<int> v;
  while (true) {
    char c;
    cin >> c;
    if (c == '?') {
      if (op == '+') {
        v.push_back(+1);
      } else {
        v.push_back(-1);
      }
    } else {
      op = c;
    }
    if (c == '=') break;
  }
  int s;
  cin >> s;
  int n = size(v);
  int x = count(begin(v), end(v), +1), y = n - x;
  if (s * x - y < s or x - s * y > s) {
    cout << "Impossible\n";
    exit(0);
  }
  cout << "Possible\n";
  int rest = s - (x - s * y);
  for (int i = 0; i < n; ++i) {
    int t = min(rest, s - 1);
    if (v[i] > 0) {
      if (i) cout << " + ";
      cout << 1 + t;
    } else {
      if (i) cout << " - ";
      cout << s - t;
    }
    rest -= t;
  }
  cout << " = " << s << '\n';
}