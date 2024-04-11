#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  int n, k;
  cin >> n >> k;
  vector<ll> ans(n);
  vector<pair<pair<int, int>, int> > ar(n);
  for (int i = 0; i < n; ++i) {
    cin >> ar[i].first.first;
  }
  for(int i = 0; i < n; ++i) {
    cin >> ar[i].first.second;
    ar[i].second = i;
  }
  sort(ar.begin(), ar.end());

  vector<int> v;
  ll sm = 0;
  for (auto p: ar) {
    ans[p.second] = p.first.second + sm;
    v.push_back(p.first.second);
    sm += p.first.second;
    if (v.size() > k) {
      sort(v.begin(), v.end());
      sm -= v[0];
      v.erase(v.begin());
    }
  }
  for(int i = 0; i < n; ++i) {
    cout << ans[i] << " ";
  }
  cout << "\n";

}