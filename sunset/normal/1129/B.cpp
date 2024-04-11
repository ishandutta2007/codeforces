#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int k;
  cin >> k;
  vector<int> a;
  a.push_back(-1);
  ++k;
  while (true) {
    if (k >= (int) 1e6) {
      a.push_back((int) 1e6);
      ++k;
      k -= (int) 1e6;
    } else {
      a.push_back(k + 1);
      break;
    }
  }
  cout << a.size() << "\n";
  for (int i = 0; i < (int) a.size(); ++i) {
    if (i) {
      cout << " ";
    }
    cout << a[i];
  }
  cout << "\n";
  return 0;
}