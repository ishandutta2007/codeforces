#include <iostream>
using namespace std;

int main() {
  int n, k, m, t;
  cin >> n >> k >> m >> t;
  int l = n;
  for(int i = 0; i < t; ++i) {
    int q, x;
    cin >> q >> x;
    if (q == 0) {
      if (x < k) {
        k -= x;
        l -= x;
      } else {
        l = x;
      }
    } else {
      if (x <= k) ++k;
      ++l;
    }
    cout << l << " " << k << "\n";
  }
}