#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
  ll n, h, m, k;
  cin >> n >> h >> m >> k;
  ll m2 = m / 2, val = 0, bst = 0, mn;
  map<ll, ll> df;
  vector<ll> M;  
  for (ll i = 0; i < n; i++) {
    ll hh, mm;
    cin >> hh >> mm;    
    M.push_back(mm);
    ll st = (mm - k + m2 + 1) % m2;
    ll fn = mm % m2;
    df[st]++;
    df[fn]--;
    if (st > fn) val++;
    // cout << st << " " << fn << endl;
  }
  mn = 1005000;
  for (const auto &it : df) {
    val += it.second;
    if (val < mn) {
      mn = val;
      bst = it.first;
    }
  }
  cout << mn << " " << (bst + k) % m2 << "\n";
  bst += m + k;
  for (ll i = 0; i < n; i++) {
    ll mm = M[i] % m2;
    while (mm + m2 < bst) mm += m2;
    if (mm > bst - k) cout << i + 1 << " ";
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ll t = 1;
#ifdef SERT
  t = 1;
#endif
  while (t--) {
    solve();
  }
}