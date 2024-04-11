#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n), b;
    vector<bool> vis(n * 2);
    for (int &x : a) cin >> x, vis[--x] = true;
    for (int i = 0; i < n * 2; ++i)
      if (!vis[i]) b.push_back(i);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int mn = 0, mx = 0;
    auto p = b.begin();
    for (int x : a) {
      if (*p < x) ++p;
      else ++mn;
    }

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    p = b.begin(); mx = n;
    for (int x : a) {
      if (*p > x) ++p;
      else --mx;
    }
    cout << mx - mn + 1 << '\n';
  }
  return 0;
}