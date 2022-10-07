#include <bits/stdc++.h>
using namespace std;


int ask(vector<int> a, vector<int> b) {
  cout << a.size() << " " << b.size() << " ";
  for (auto i: a) {
    cout << i << " ";
  }
  for (auto i: b) {
    cout << i << " ";
  }
  cout << "\n";
  cout.flush();
  int ans;
  cin >> ans;
  return ans;
}

int main() {
  int T;
  cin >> T;
  for(int t = 0; t < T; ++t) {
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 0; i < 7; ++i) {
      vector<int> on, off;
      for(int j = 1; j <= n; ++j) {
        if ((j >> i) & 1) {
          on.push_back(j);
        } else {
          off.push_back(j);
        }
      }
      if (!(on.size() > 0 && off.size() > 0)) continue;
      int v = ask(on, off);
      if (v == -1) {
        throw "gg";
      }
      ans = max(ans, v);
    }
    cout << "-1 " << ans << "\n";
    cout.flush();
  }
}