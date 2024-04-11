#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

int go() {
  int p, y;
  cin >> p >> y;
  for(int i = y; i > p; --i) {
    bool good = true;
    for(int j = 2; j <= p; ++j) {
      if (i % j == 0) { good = false; break; }
      if (j * j > i) break;
    }
    if (good) return i;
    if (i + 5000 < y) break;
  }
  return -1;
}


int main() {
  cout << go() << "\n";
}