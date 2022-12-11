#include <bits/stdc++.h>
using namespace std;

const int MAX_E = 4;

struct DP {
  int ans;
  vector<int> ends;
  DP(int ans = 0, const vector<int> &ends = {}): ans(ans), ends(ends) {}
};

void solve() {
  int n;
  cin >> n;
  if (n <= 2) { cout << n << "\n"; return; }

  int ans = 1;
  int lst, cur; 
  cin >> cur;
  set<int> ends = {-1};  
  
  for (int it = 1; it < n; it++) {
    lst = cur; cin >> cur;
    if (ends.size() == 1u && *ends.begin() == cur && lst == cur) continue;
    ans++;
    if (lst == cur) ends = {lst};
    else {
      if (*ends.begin() != cur) ends.insert(lst);
      if (*ends.rbegin() != cur) ends.insert(lst);
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#ifdef SERT
  solve();
  solve();
#endif
  solve();
}