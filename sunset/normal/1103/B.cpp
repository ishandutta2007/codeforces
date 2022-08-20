#include <bits/stdc++.h>

using namespace std;

int main() {
  string type;
  while (cin >> type) {
    if (type == "end") {
      break;
    }
    int w = 1;
    while (true) {
      cout << "? " << w << " " << w * 2 << endl;
      cin >> type;
      if (type == "x") {
        break;
      }
      w <<= 1;
    }
    cout << "? " << w - 1 << " " << w << endl;
    cin >> type;
    if (type == "x") {
      cout << "! " << w << endl;
      continue;
    }
    int l = w + 1, r = w << 1;
    while (l < r) {
      int mid = l + r >> 1;
      cout << "? " << w << " " << mid << endl;
      cin >> type;
      if (type == "x") {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    cout << "! " << r << endl;
  }
  return 0;
}