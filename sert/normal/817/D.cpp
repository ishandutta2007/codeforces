#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll getMax(const vector<int> &a) {
  int n = a.size();
  set<int> pos;
  pos.insert(-1);
  pos.insert(n);
  ll ans = 0;

  vector<pair<int, int>> v;
  for (int i = 0; i < n; i++) v.emplace_back(a[i], i);
  sort(v.rbegin(), v.rend());

  for (int i = 0; i < n; i++) {
    int p = v[i].second;
    auto it = pos.upper_bound(p);
    int r = *it;
    it--;
    int l = *it;
    ans += (1ll * r - p) * (1ll * p - l) * v[i].first;
    pos.insert(p);
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &x : a) cin >> x;
  ll mx = getMax(a);
  for (int &x : a) x *= -1;
  ll mn = getMax(a);
  cout << mx + mn << "\n";
  return 0;
}