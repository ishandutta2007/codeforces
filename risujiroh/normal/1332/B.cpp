#include <bits/stdc++.h>
using namespace std;

template <class T> pair<vector<int>, vector<T>> zip(vector<T> a) {
  int n = a.size();
  vector<pair<T, int>> p(n);
  for (int i = 0; i < n; ++i) p[i] = {a[i], i};
  sort(begin(p), end(p));
  vector<T> v;
  for (int k = 0, t = -1; k < n; ++k) {
    if (k == 0 or p[k - 1].first < p[k].first) v.push_back(p[k].first), ++t;
    a[p[k].second] = t;
  }
  return {a, v};
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> res(n, -1);
    for (int i = 0; i < n; ++i) {
      int a;
      cin >> a;
      for (int p : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31}) {
        if (a % p == 0) {
          res[i] = p;
          break;
        }
      }
      assert(res[i] != -1);
    }
    res = zip(res).first;
    cout << *max_element(begin(res), end(res)) + 1 << '\n';
    for (int i = 0; i < n; ++i) {
      cout << res[i] + 1 << " \n"[i == n - 1];
    }
  }
}