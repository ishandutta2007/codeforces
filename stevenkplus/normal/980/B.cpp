#include <bits/stdc++.h>
using namespace std;

#define repi(i, a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); ++i) 
typedef long double ld;

const int MAXN = 100100;
int ar[4][MAXN];

int main() {
  int n, m;
  cin >> n >> m;
  cout << "YES\n";
  if (m % 2 == 1) {
    ar[1][n/2] = 1;
    --m;
  } else if (m > 0) {
    ar[1][n/2] = 1;
    ar[2][n/2] = 1;
    m -= 2;
  }

  int _j = 1;
  int _i = 1;
  while (m > 0) {
    ar[_i][_j] = 1;
    ar[_i][n - 1 - _j] = 1;
    ++_j;
    if (_j >= n - 1 - _j) {
      _j = 1;
      ++_i;
    }
    m -= 2;
  }


  for(int i = 0; i < 4; ++i) {
    for(int j = 0; j < n; ++j) {
      if (ar[i][j]) {
        cout << '#';
      } else {
        cout << '.';
      }
    }
    cout << "\n";
  }
}