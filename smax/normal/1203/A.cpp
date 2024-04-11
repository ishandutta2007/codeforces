#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int q;
  cin >> q;
  while (q--) {
    int n, prev = -1;
    bool clockwise = true, counterclockwise = true;
    cin >> n;
    for (int i=0; i<n; i++) {
      int p;
      cin >> p;
      if (prev != -1 && p - prev != 1 && p + n - prev != 1)
        clockwise = false;
      if (prev != -1 && p - prev != -1 && p - prev - n != -1)
        counterclockwise = false;
      prev = p;
    }

    if (clockwise || counterclockwise)
      cout << "YES\n";
    else
      cout << "NO\n";
  }

  return 0;
}