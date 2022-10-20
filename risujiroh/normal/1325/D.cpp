#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  long long u, v;
  cin >> u >> v;
  if (u > v or (u & 1) != (v & 1)) {
    cout << "-1\n";
    exit(0);
  }
  if (u == 0 and v == 0) {
    cout << "0\n";
    exit(0);
  }
  if (u == v) {
    cout << "1\n";
    cout << u << '\n';
    exit(0);
  }
  if (u & (v - u) / 2) {
    cout << "3\n";
    cout << u << ' ' << (v - u) / 2 << ' ' << (v - u) / 2 << '\n';
  } else {
    cout << "2\n";
    cout << (v - u) / 2 << ' ' << (u | (v - u) / 2) << '\n';
  }
}