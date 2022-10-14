#include <bits/stdc++.h>

#define pb push_back
// #define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ld long double
using namespace std;

void sas(vector<int> a) {
  int v = a.back();
  a.pop_back();
  for (auto x : a) {
    cout << x << '.';
  }
  cout << v;
  cout << '\n';
}

void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i = 0; i < n; i++) cin >> A[i];
  vector<vector<int>> ans(n);
  ans[0] = {1};
  cout << "1\n";
  vector<pair<int, int>> st;
  st.pb({1, 0});
  for (int i = 1; i < n; i++) {
    if (A[i] == 1) {
      ans[i] = ans[i - 1];
      ans[i].pb(A[i]);
      st.pb({A[i], i});
    } else {
      while (!st.empty() && st.back().first + 1 != A[i]) {
        st.pop_back();
      }
      int j = st.back().second;
      st.pop_back();
      ans[i] = ans[j];
      ans[i].back()++;
      st.pb({A[i], i});
    }
    sas(ans[i]);
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}