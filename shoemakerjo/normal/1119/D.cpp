#include <bits/stdc++.h>

using namespace std;

using ll = long long;
int n;
const int maxn = 100010;

ll pref[maxn];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;

  vector<ll> si;
  ll cur;
  for (int i = 0; i < n; i++) {
    cin >> cur;
    si.push_back(cur);
  }
  sort(si.begin(), si.end());

  vector<ll> diffs;
  for (int i = 0; i < si.size()-1; i++) {
    diffs.push_back(si[i+1]-si[i]);
  }
  sort(diffs.begin(), diffs.end());

  for (int i = 0; i < diffs.size(); i++) {
    if (i) pref[i] = pref[i-1];
    pref[i] += diffs[i];
  }

  ll l, r;
  int q;
  cin >> q;
  while (q--) {
    cin >> l >> r;

    ll numin = r-l+1;
    // cout << numin<< ":";
    // ll res = numin;
    ll res = 0LL;

    int sp = upper_bound(diffs.begin(), diffs.end(), numin) - diffs.begin() - 1;
    if (sp != -1) res += pref[sp];

    res += (diffs.size() - (sp+1) + 1) * numin;

    cout << res << " ";

  }
  // cout.flush();
  cout << endl;
}