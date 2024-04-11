#include <iostream>
using namespace std;

int n, a[100000];
int main() {
  int t;
  cin >> t;
  while ( t-- ) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    bool inc = true;
    for (int i = 0; i + 1 < n; i++) {
      inc &= a[i + 1] > a[i];
    }
    cout << (n % 2 == 1 && inc ? "NO" : "YES") << endl;
  }
  return 0;
}