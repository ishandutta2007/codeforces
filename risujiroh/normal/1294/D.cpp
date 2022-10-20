#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int q, x;
  cin >> q >> x;
  vector<int> a(x);
  vector<set<int>> idx(q + 1);
  multiset<int> ms;
  for (int i = 0; i < x; ++i) {
    idx[0].insert(i);
    ms.insert(0);
  }
  while (q--) {
    int y;
    cin >> y;
    y %= x;
    idx[a[y]].erase(y);
    ms.erase(ms.find(a[y]));
    ++a[y];
    idx[a[y]].insert(y);
    ms.insert(a[y]);
    int mn = *begin(ms);
    int i = *begin(idx[mn]);
    cout << mn * x + i << '\n';
  }
}