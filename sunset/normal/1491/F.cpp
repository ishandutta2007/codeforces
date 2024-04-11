#include <bits/stdc++.h>

using namespace std;

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    int p = -1, f = 0;
    for (int i = 1; i <= n; ++i) {
      cout << "? 1 " << n - i << endl;
      cout << i << endl;
      for (int j = i + 1; j <= n; ++j) {
        if (j != i + 1) {
          cout << " ";
        }
        cout << j;
      }
      cout << endl;
      int r;
      cin >> r;
      if (r) {
        p = i;
        f = r;
        break;
      }
    }
    vector<int> bad;
    for (int i = p + 1; i < n; ++i) {
      cout << "? 1 1" << endl;
      cout << p << endl;
      cout << i << endl;
      int r;
      cin >> r;
      if (r) {
        f -= r;
      } else {
        bad.push_back(i);
      }
    }
    if (!f) {
      bad.push_back(n);
    }
    if (p != 1) {
      int low = 1, high = p;
      while (low < high) {
        int mid = (low + high) / 2;
        cout << "? 1 " << mid - low + 1 << endl;
        cout << p << endl;
        for (int i = low; i <= mid; ++i) {
          if (i != low) {
            cout << " ";
          }
          cout << i;
        }
        cout << endl;
        int r;
        cin >> r;
        if (r) {
          high = mid;
        } else {
          low = mid + 1;
        }
      }
      for (int i = 1; i < p; ++i) {
        if (i != low) {
          bad.push_back(i);
        }
      }
    }
    sort(bad.begin(), bad.end());
    cout << "! " << bad.size();
    for (int i : bad) {
      cout << " " << i;
    }
    cout << endl;
  }
  return 0;
}