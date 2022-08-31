#include <bits/stdc++.h>
using namespace std;
const int LOG = 30;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  int q;
  cin >> q;
  vector<int> a(q), b(q);
  for (int i = 0; i < q; i++){
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
  }
  if (n > m){
    swap(n, m);
    for (int i = 0; i < q; i++){
      swap(a[i], b[i]);
    }
  }
  set<pair<int, int>> st;
  for (int i = 0; i < q; i++){
    st.insert(make_pair(a[i], b[i]));
  }
  vector<int> dp(n, -1);
  dp[0] = 0;
  int ans = 0;
  while (true){
    ans++;
    vector<int> dp2(n, -1);
    for (int i = 0; i < n; i++){
      if (dp[i] != -1){
        if (st.count(make_pair(i, dp[i])) == 0){
          int x = min(i + dp[i] + 1, m - 1);
          dp2[i] = max(dp2[i], x);
          int y = min(i + dp[i] + 1, n - 1);
          dp2[y] = max(dp2[y], dp[i]);
        } else {
          int x = min(i + dp[i] + 2, m - 1);
          dp2[i] = max(dp2[i], x);
          int y = min(i + dp[i] + 2, n - 1);
          dp2[y] = max(dp2[y], dp[i]);
        }
      }
    }
    if (dp2[n - 1] == m - 1){
      cout << ans << endl;
      break;
    }
    swap(dp, dp2);
  }
}