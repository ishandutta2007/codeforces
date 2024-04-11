#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k;
ll A, B;
typedef pair<ll, ll> pll;
int main()  {
  cin >> n >> k >> A >> B;
  vector<pair<pll, int> > v;
  map<int, int> m;
  for (int i = 0; i < k; ++i) {
    int x;
    cin >> x;
    --x;
    ++m[x];
  }
  for (auto p: m) {
    v.emplace_back(pll(p.first, p.second * B), p.second);
  }
  sort(v.begin(), v.end());
  for(int j = 1; j <= n; ++j) {
    int msk = -(1 << j);
    vector<pair<pll, int> > w;
    for (int i = 0; i < v.size(); ++i) {
      if (i + 1 < v.size() && (v[i].first.first & msk) == (v[i + 1].first.first & msk)) {
        w.emplace_back(pll(v[i].first.first & msk, v[i].first.second + v[i + 1].first.second), v[i].second + v[i + 1].second);
        ++i;
      } else {
        w.emplace_back(pll(v[i].first.first & msk, min(v[i].second * B * (1 << j), v[i].first.second + A)), v[i].second);
      }
    }
    v = w;
  }
  cout << v[0].first.second << "\n";
}