#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define LOG(f...) fprintf(stderr, f)

int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int p1 = -1, p2 = -1, rep;
    for (int i = 2; i <= n; ++i) {
      cout << "? " << i - 1 << " 1" << endl;
      for (int j = 1; j < i; ++j) cout << j << ' ';
      cout << endl;
      cout << i << endl;
      cin >> rep;
      if (rep != 0) { p2 = i; break; }
    }
    int L = 1, R = p2 - 1, mid;
    while (L <= R) {
      mid = (L + R) >> 1;
      cout << "? " << mid << " 1" << endl;
      for (int i = 1; i <= mid; ++i) cout << i << ' ';
      cout << endl;
      cout << p2 << endl;
      cin >> rep;
      if (rep != 0) { p1 = mid; R = mid - 1; }
      else L = mid + 1;
    }
    vector<int> res = {p1, p2};
    for (int i = p2 + 1; i <= n; ++i) {
      cout << "? 1 1" << endl;
      cout << p2 << endl << i << endl;
      cin >> rep;
      if (rep != 0) res.push_back(i);
    }
    cout << "! ";
    cout << n - res.size() << ' ';
    int last = 0;
    for (int x : res) {
      for (int i = last + 1; i < x; ++i) cout << i << ' ';
      last = x;
    }
    for (int i = last + 1; i <= n; ++i) cout << i << ' ';
    cout << endl;
  }
}