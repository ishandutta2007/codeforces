#include <bits/stdc++.h>
using namespace std;

#define repi(i, a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); ++i) 
typedef long double ld;

int main() {
  string s;
  cin >> s;
  int n = 0;
  int m = 0;
  repi(i, s) {
    if (*i == '-') {
      ++n;
    } else {
      ++m;
    }
  }
  if (m == 0 || n % m == 0) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}