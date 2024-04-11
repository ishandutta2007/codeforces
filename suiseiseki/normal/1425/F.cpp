#include <iostream>
using namespace std;

int a[1005];

int main() {
  int n, x;
  cin >> n;
  for (int i = 1; i < n; ++i) {
    cout << "? " << i << ' ' << n << endl;
    cin >> a[i];
  }
  cout << "? " << n - 2 << ' ' << n - 1 << endl;
  cin >> x;
  cout << "! ";
  for (int i = 1; i < n - 1; ++i)
    cout << a[i] - a[i + 1] << ' ';
  int an = a[n - 2] - x;
  int an1 = a[n - 1] - an;
  cout << an1 << ' ' << an << endl;
  cout << endl;
  return 0;
}