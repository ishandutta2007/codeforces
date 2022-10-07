#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 200100;
int ar[MAXN];
int main() {
  int T;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
      cin >> ar[i];
    }
    bool found = false;
    for(int i = 0; i +1 < n; ++i) {
      if (abs(ar[i] - ar[i + 1]) >= 2) {
        cout << "YES\n";
        cout << i + 1 << " " << i + 2 << "\n";
        found = true;
        break;
      }
    }
    if (!found) {
      cout << "NO\n";
    }
  }
}