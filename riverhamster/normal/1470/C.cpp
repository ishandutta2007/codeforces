#include <iostream>
#include <algorithm>
using namespace std;

int query(int x) {
  int answer = 0;
  cout << "? " << x + 1 << endl;
  cin >> answer;
  return answer;
}

int main() {
  int n, x;
  cin >> n >> x;
  query(0);
  int p = 1;
  for (int i = 1; p <= n; ++i, p = (p + i) % n) {
    int v = query(p);
    if (v != x) {
      int j;
      if (v > x) {
        for (j = p - 1; query(j) != x; j = (j + n - 1) % n);
        cout << "! " << j + 1 << endl;
      }
      else {
        for (j = p + 1; query(j) != x; j = (j + 1) % n);
        cout << "! " << j + 1 << endl;
      }
      return 0;
    }
  }
  return 0;
}