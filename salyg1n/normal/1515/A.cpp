#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  for (int T = 0; T < t; ++T) {
    int n, x;
    cin >> n >> x;
    vector<int> w(n);
    for (auto& i : w)
      cin >> i;
    sort(w.begin(), w.end());
    int sum = 0;
    for (int i = 0; i < w.size(); ++i) {
        sum += w[i];
        if (sum == x && i != w.size() - 1)
        swap(w[i], w[i+1]);
    }
    if (sum == x)
      cout << "NO\n";
    else {
      cout << "YES\n";
      for (auto i : w)
        cout << i << " ";
      cout << "\n";
    }
  }
  return 0;
}