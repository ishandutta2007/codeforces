#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int q;
  cin >> q;
  while (q--) {
    int n, numOdd = 0, freq[10001] = {0};
    vector<int> sides;
    cin >> n;
    for (int i=0; i<4*n; i++) {
      int a;
      cin >> a;
      freq[a]++;
      if (freq[a] % 2 == 1) {
        numOdd++;
        sides.push_back(a);
      } else
        numOdd--;
    }

    if (numOdd)
      cout << "NO\n";
    else {
      sort(sides.begin(), sides.end());
      int area = sides[0] * sides[sides.size()-1];
      bool sol = true;
      for (int i=1; i<sides.size()/2; i++)
        if (sides[i] * sides[sides.size()-i-1] != area) {
          cout << "NO\n";
          sol = false;
          break;
        }
      if (sol)
        cout << "YES\n";
    }
  }

  return 0;
}