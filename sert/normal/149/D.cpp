#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MD = (ll)1e9 + 7;
const int N = 703;

map<string, ll> mp;
ll dp[N][N][3][3];
int match[N];

ll getDP(int l, int r, int cl, int cr) {
  if (l + 2 == r) 
    return dp[l][r][cl][cr] = 4 - !!cl - !!cr;
  
  string key = to_string(l) + '#' + to_string(r) + to_string(cl) + to_string(cr);
  if (mp.count(key)) return mp[key];

  int m = match[l];

  // cout << l << " " << r << " " << cl << " " << cr << " --" << m << endl;
  ll ans = 0;
  for (int cL = 0; cL < 3; cL++) {
    for (int cR = 0; cR < 3; cR++) {
      if (cL + cR == 0 || cL * cR > 0 || (cl == cL && cl > 0)) continue;

      if (m + 1 == r) {
        if (cR == cr && cr > 0) continue;
        ans += getDP(l + 1, r - 1, cL, cR);
        continue;
      }

      if (l + 1 == m) {
        if (cL + cR == 0 || cL * cR > 0) continue;
        ans += getDP(m + 1, r, cR, cr);
        continue;
      }
      
      ans += getDP(l + 1, m, cL, cR) * getDP(m + 1, r, cR, cr);
    }
  }

  ans %= MD;
  // cout << l << " " << r << " " << cl << " " << cr << " " << ans << endl;
  dp[l][r][cl][cr] = ans;
  mp[key] = ans;
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;
  int n = s.length();
  
  vector<int> v;
  for (int i = 0; i < n; i++) {
    if (s[i] == '(') v.push_back(i);
    else {
      match[v.back()] = i;
      match[i] = v.back();
      v.pop_back();
    }
  }

  ll ans = getDP(0, n, 0, 0);
  cout << ans % MD << endl;
}