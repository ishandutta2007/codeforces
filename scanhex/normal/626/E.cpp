#include <bits/stdc++.h>

using namespace std;
using nagai = long long;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; 
  cin >> n;
  vector<int>a(n);
  for(auto& x : a) cin >> x;
  sort(a.begin(),a.end());
  long double res = 0;
  vector<int> rs = {a[0]};
  vector<nagai> pref(n + 1);
  for(int i = 0; i < n ;++i) pref[i + 1] = pref[i] + a[i];
  vector<int> ord(n);
  iota(ord.begin(), ord.end(), 0);
  shuffle(ord.begin(), ord.end(), mt19937());
  for(int m : ord) {
	  int L = 0, R = min(m + 1, n - m);
	  while (R - L > 1) {
		  int M = (L + R) / 2;
		  int k = M;
		  nagai olds = pref[n] - pref[n - (k - 1)] + pref[m + 1] - pref[m - (k - 1)];
		  nagai news = pref[n] - pref[n - k] + pref[m + 1] - pref[m - k];
		  if (olds * (2 * k + 1) > news * (2 * k - 1)) 
			  R = M;
		  else
			  L = M;
	  }
	  if (L > 0) {
		  assert(L <= m);
		  long double val = (pref[n] - pref[n - L] + pref[m + 1] - pref[m - L]) / (long double)(2 * L + 1) - a[m];
		  if (val > res) {
			  res = val;
			  rs.clear();
			  for(int i = 0; i < L; ++i) 
				  rs.push_back(a[n - 1 - i]), rs.push_back(a[m - i]);
			  rs.push_back(a[m - L]);
		  }
	  }
  }
  cout << rs.size() << '\n';
  for(auto& x : rs) cout << x << ' ';
  cout << '\n';
  return 0;
}