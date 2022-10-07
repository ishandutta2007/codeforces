#include <iostream>
#include <algorithm>
using namespace std;
int main() {
  int T;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n, a, b;
    cin >> n >> a >> b;
    int x = 0, y = 0;
    for(int i = 0; i < a; ++i) {
      int p;
      cin >> p;
      x = max(x, p);
    }
    for(int i = 0; i < b; ++i) {
      int p;
      cin >> p;
      y = max(y, p);
    }
    if (x > y) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}